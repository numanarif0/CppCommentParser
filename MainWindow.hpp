#ifndef CMT_PARSER_MAINWINDOW_HPP
#define CMT_PARSER_MAINWINDOW_HPP

#include <gtkmm.h>
#include "Parser.hpp"
#include <vector>
#include <string>
#include <thread>
#include <mutex>

// Artık Gtk::Window'dan miras almıyor.
class MainWindow {
public:
    // Kurucu metot artık basit.
    MainWindow();
    virtual ~MainWindow();

    // Ana programın, bu sınıfın yönettiği pencereye erişmesi için.
    Gtk::Window* get_window();

protected:
    void on_select_files_clicked();
    void on_requirements_clicked();
    void on_extract_clicked();
    void on_delete_clicked();
    void on_file_row_activated(Gtk::ListBoxRow* row);
    void on_extraction_finished();
    void on_export_csv_clicked();
    void on_export_pdf_clicked();
    
private:
    void process_file_in_thread(const std::string& path);

    Glib::RefPtr<Gtk::Builder> m_builder;
    
    Glib::RefPtr<Gtk::FileDialog> m_file_dialog;
    Gtk::Window* m_pWindow = nullptr;
    
    Gtk::Label* m_pStatusLabel = nullptr;
    Gtk::Label* m_pReqFileTracker = nullptr;
    Gtk::Label* m_pFileCountLabel = nullptr;
    Gtk::Button* m_pSelectFilesButton = nullptr;    
    Gtk::Button* m_pExtractButton = nullptr;
    Gtk::Button* m_pDeleteButton = nullptr;
    Gtk::Button* m_pRequirementsButton = nullptr;
    Gtk::ListBox* m_pFileListbox = nullptr;
    Gtk::ListBox* m_pIssuesListbox = nullptr;
    Gtk::Button* m_pExportCsvButton = nullptr;
    Gtk::Button* m_pExportPdfButton = nullptr;
    //isimlendirme standartı 
    std::mutex m_mutex;
    int m_csv_export_counter = 0; 
   
    Parser m_parser;
    std::string m_requirements_file_path;
    std::vector<std::string> m_file_paths;
    std::unordered_map<std::string, Gtk::Picture*> m_extract_icons;
    std::unordered_map<std::string, std::vector<Issue>> m_issues;

    Glib::Dispatcher m_dispatcher_extraction_finished;
    int m_total_files_to_process = 0;
    int m_processed_files_count = 0;
    
};

#endif