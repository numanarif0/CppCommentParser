#include "MainWindow.hpp"
#include <iostream>
#include <giomm.h>
#include <glibmm/miscutils.h>
#include <algorithm>
#include <fstream> 
#include <glibmm/error.h>



MainWindow::MainWindow()
{
    
    m_builder = Gtk::Builder::create_from_file("window.ui");


    m_pWindow = m_builder->get_widget<Gtk::Window>("main_window");
    if (!m_pWindow) {
        throw std::runtime_error("Error: Could not get 'main_window' from UI file.");
    }
    
    // 3. Diğer tüm widget'ları al.
    m_pStatusLabel = m_builder->get_widget<Gtk::Label>("status_label");
    m_pReqFileTracker = m_builder->get_widget<Gtk::Label>("req_file_tracker");
    m_pFileCountLabel = m_builder->get_widget<Gtk::Label>("file_count_label");
    m_pSelectFilesButton = m_builder->get_widget<Gtk::Button>("select_files_button");
    m_pExtractButton = m_builder->get_widget<Gtk::Button>("extract_button");
    m_pDeleteButton = m_builder->get_widget<Gtk::Button>("delete_button");
    m_pRequirementsButton = m_builder->get_widget<Gtk::Button>("requirements_select_button");
    m_pFileListbox = m_builder->get_widget<Gtk::ListBox>("file_list_box");
    m_pIssuesListbox = m_builder->get_widget<Gtk::ListBox>("issues_list_box");
    m_pExportCsvButton = m_builder->get_widget<Gtk::Button>("export_csv_button");
    m_pExportPdfButton = m_builder->get_widget<Gtk::Button>("export_pdf_button");
    m_file_dialog = Gtk::FileDialog::create();
    

    // 4. Sinyalleri bağla.
    m_pSelectFilesButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_select_files_clicked));
    m_pExtractButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_extract_clicked));
    m_pDeleteButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_delete_clicked));
    m_pRequirementsButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_requirements_clicked));
    m_pFileListbox->signal_row_activated().connect(sigc::mem_fun(*this, &MainWindow::on_file_row_activated));
    m_pExportCsvButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_export_csv_clicked));
    m_pExportPdfButton->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_export_pdf_clicked));
    
    m_dispatcher_extraction_finished.connect(sigc::mem_fun(*this, &MainWindow::on_extraction_finished));
    m_pExportCsvButton->set_sensitive(false);
    m_pExportPdfButton->set_sensitive(false);
}

MainWindow::~MainWindow() {
   
}


Gtk::Window* MainWindow::get_window() {
    return m_pWindow;
}


void MainWindow::on_select_files_clicked() {
 
    m_file_dialog = Gtk::FileDialog::create();
    m_file_dialog->set_title("Select Files");


    m_file_dialog->open_multiple(*m_pWindow, [this](const Glib::RefPtr<Gio::AsyncResult>& result) {
        try {
            auto files = m_file_dialog->open_multiple_finish(result);
            
            if (!files.empty()) {
                for (const auto& file : files) {
                    if (file) {
                        std::string path = file->get_path();
                        if (std::find(m_file_paths.begin(), m_file_paths.end(), path) == m_file_paths.end()) {
                            m_file_paths.push_back(path);
                            auto row = Gtk::make_managed<Gtk::ListBoxRow>();
                            auto box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
                            auto label = Gtk::make_managed<Gtk::Label>(Glib::path_get_basename(path));
                            auto icon = Gtk::make_managed<Gtk::Picture>();
                            label->set_xalign(0.0);
                            label->set_expand(true);
                            box->append(*label);
                            box->append(*icon);
                            row->set_child(*box);
                            row->set_name(path);
                            m_pFileListbox->append(*row);
                            m_extract_icons[path] = icon;
                        }
                    }
                }
                m_pFileCountLabel->set_text(std::to_string(m_file_paths.size()) + " files");
                m_pStatusLabel->set_text("Files loaded.");
            }
        } catch (const Glib::Error& e) {
            std::cerr << "Error opening files: " << e.what() << std::endl;
        }
    });
}

void MainWindow::on_requirements_clicked() {
    
    m_file_dialog = Gtk::FileDialog::create();
    m_file_dialog->set_title("Select Requirements File");

   
    m_file_dialog->open(*m_pWindow, [this](const Glib::RefPtr<Gio::AsyncResult>& result) {
        try {
            auto file = m_file_dialog->open_finish(result);
            if (file) {
                m_requirements_file_path = file->get_path();
                m_pReqFileTracker->set_text(Glib::path_get_basename(m_requirements_file_path));
                m_pStatusLabel->set_text("Requirements file set.");
                if (!m_file_paths.empty()) m_pExtractButton->set_sensitive(true);
            }
        } catch (const Glib::Error& e) {
            std::cerr << "Error selecting requirement file: " << e.what() << std::endl;
        }
    });
}

void MainWindow::on_extract_clicked() {
    if (m_file_paths.empty() || m_requirements_file_path.empty()) return;
    
    m_pStatusLabel->set_text("Extracting...");
    m_issues.clear();
    m_processed_files_count = 0;
    m_total_files_to_process = m_file_paths.size();
    
    for (const auto& path : m_file_paths) {
        std::thread(&MainWindow::process_file_in_thread, this, path).detach();
    }
}

void MainWindow::process_file_in_thread(const std::string& path) {
    Parser local_parser;
    auto issues_found = local_parser.parse_file(path, m_requirements_file_path);
    
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_issues[path] = issues_found;
        m_processed_files_count++;
    }
    
    m_dispatcher_extraction_finished.emit();
}

void MainWindow::on_extraction_finished() {
   
    std::lock_guard<std::mutex> lock(m_mutex);
    
    
    if (m_processed_files_count == m_total_files_to_process) {
        m_pStatusLabel->set_text("Extraction complete.");

        bool issues_were_found = false;
        for (const auto& pair : m_issues) {
            
            if (!pair.second.empty()) {
                issues_were_found = true;
                break; 
            }
        }
        if (issues_were_found) {
            m_pExportCsvButton->set_sensitive(true);
            m_pExportPdfButton->set_sensitive(true);
        }
    }
}

void MainWindow::on_file_row_activated(Gtk::ListBoxRow* row) {
    if (!row) return;
    std::string path = row->get_name();
    
    while(auto* child = m_pIssuesListbox->get_first_child()) {
        m_pIssuesListbox->remove(*child);
    }

    if (m_issues.count(path) > 0) {
        const auto& issues_for_file = m_issues.at(path);
        if (issues_for_file.empty()) {
            m_pIssuesListbox->append(*Gtk::make_managed<Gtk::Label>("No issues found."));
        } else {
            std::unordered_map<std::string, Gtk::Box*> expander_boxes;
            for (const auto& issue : issues_for_file) {
                 if(expander_boxes.count(issue.function_name) == 0){
                     auto expander = Gtk::make_managed<Gtk::Expander>(issue.function_name);
                     auto box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 5);
                     expander->set_child(*box);
                     m_pIssuesListbox->append(*expander);
                     expander_boxes[issue.function_name] = box;
                 }
                 auto issue_label = Gtk::make_managed<Gtk::Label>(issue.issue_value);
                 issue_label->set_xalign(0.0);
                 expander_boxes.at(issue.function_name)->append(*issue_label);
            }
        }
    }
}

void MainWindow::on_delete_clicked() {
    auto selected_rows = m_pFileListbox->get_selected_rows();
    std::vector<Gtk::Widget*> to_delete;
    for (auto* row : selected_rows) {
        to_delete.push_back(row);
    }
    
    for(auto* widget : to_delete){
        std::string path_to_delete = widget->get_name();
        
        m_file_paths.erase(std::remove(m_file_paths.begin(), m_file_paths.end(), path_to_delete), m_file_paths.end());
        m_issues.erase(path_to_delete);
        m_extract_icons.erase(path_to_delete);
        
        m_pFileListbox->remove(*widget);
    }
    m_pFileCountLabel->set_text(std::to_string(m_file_paths.size()) + " files");
}

void MainWindow::on_export_csv_clicked() {
 
    std::vector<Issue> all_issues;
    for (const auto& pair : m_issues) {
        all_issues.insert(all_issues.end(), pair.second.begin(), pair.second.end());
    }

    if (all_issues.empty()) {
        m_pStatusLabel->set_text("Dışa aktarılacak veri yok.");
        return;
    }

   

    std::string suggested_filename = "issues.csv"; 

 
    if (!m_file_paths.empty()) {
   
        std::string basename = Glib::path_get_basename(m_file_paths.front());

     
        auto dot_pos = basename.rfind('.');
        if (dot_pos != std::string::npos) {
            basename = basename.substr(0, dot_pos);
        }
      
        if (m_csv_export_counter == 0) {
            suggested_filename = basename + "_issues.csv";
        } else {
            suggested_filename = basename + "_issues (" + std::to_string(m_csv_export_counter) + ").csv";
        }
    }
    
  
    m_csv_export_counter++;
    
    


 
    m_file_dialog->set_title("CSV Olarak Kaydet");
    m_file_dialog->set_initial_name(suggested_filename); 

    m_file_dialog->save(
        *m_pWindow,
        [this, all_issues](const Glib::RefPtr<Gio::AsyncResult>& result) {
            try {
                auto file = m_file_dialog->save_finish(result);
                if (!file) { 
                    m_csv_export_counter--; 
                    return;
                }

                std::string path = file->get_path();
                std::ofstream out_file(path);
                if (out_file.is_open()) {
                    out_file << "Function Name,Issue\n";
                    for (const auto& issue : all_issues) {
                        out_file << "\"" << issue.function_name << "\",\"" << issue.issue_value << "\"\n";
                    }
                    out_file.close();
                    m_pStatusLabel->set_text("CSV dosyası başarıyla kaydedildi: " + path);
                } else {
                    m_pStatusLabel->set_text("Hata: Dosya oluşturulamadı.");
                    m_csv_export_counter--; // Sayacı geri al
                }
            }
            catch (const Glib::Error& e) {
                std::cerr << "Dosya kaydetme hatası: " << e.what() << std::endl;
                m_pStatusLabel->set_text("İşlem iptal edildi.");
                m_csv_export_counter--; // Sayacı geri al
            }
            catch (const std::exception& e) {
                std::cerr << "Beklenmedik hata: " << e.what() << std::endl;
                m_pStatusLabel->set_text("Bir hata oluştu.");
                m_csv_export_counter--; // Sayacı geri al
            }
        }
    );
}


void MainWindow::on_export_pdf_clicked()
{
    m_pStatusLabel->set_text("PDF dışa aktarma özelliği henüz eklenmemiştir.");
    std::cout << "PDF export button clicked - feature not yet implemented." << std::endl;
}