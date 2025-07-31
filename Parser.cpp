#include "parser.hpp"
#include <fstream>      
#include <sstream>      
#include <iostream>
#include <regex>        


std::vector<Issue> Parser::parse_file(const std::string& file_path, const std::string& requirements_path) {

    if (m_requirements_cache.empty()) {
        try {
            cache_requirements(requirements_path);
        } catch (const std::exception& e) {
            std::cerr << "Error caching requirements file: " << e.what() << std::endl;
       
            return {};
        }
    }

    std::vector<Issue> all_issues;


    std::ifstream input_file(file_path);
    if (!input_file.is_open()) {
        std::cerr << "Failed to open file " << file_path << std::endl;
        return {};
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input_file, line)) {
        lines.push_back(line);
    }

   
    for (size_t i = 0; i < lines.size(); ++i) {
        if (!is_function_signature(lines[i])) {
            continue; 
        }

        auto function_opt = parse_function_signature(lines[i]);
        if (!function_opt.has_value()) {
            continue; 
        }
        Function current_function = function_opt.value();

        bool found_comment = false;
        size_t comment_start_index = i;
        std::vector<std::string> comment_lines;

 
        while (comment_start_index > 0) {
            comment_start_index--;
            const std::string& potential_comment_line = lines[comment_start_index];
            if (is_function_signature(potential_comment_line)) {
                break; 
            }
            if (potential_comment_line.find("/**") != std::string::npos) {
                found_comment = true;
                break; 
            }
        }
        
        if (found_comment) {
         
            size_t current_comment_line_index = comment_start_index;
            while (current_comment_line_index < lines.size() && lines[current_comment_line_index].find("*/") == std::string::npos) {
                comment_lines.push_back(lines[current_comment_line_index]);
                current_comment_line_index++;
            }
            if (current_comment_line_index < lines.size()) {
                comment_lines.push_back(lines[current_comment_line_index]); 
            }

          
            CommentInfo info = extract_comments(comment_lines);
            std::vector<Issue> issues = compare_with_function(info, current_function);
          
            all_issues.insert(all_issues.end(), issues.begin(), issues.end());

        } else {
            
             all_issues.push_back({current_function.name, "function has no comments"});
        }
    }

    return all_issues;
}


void Parser::cache_requirements(const std::string& requirements_path) {
    std::ifstream file(requirements_path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open requirements file: " + requirements_path);
    }
    
    m_requirements_cache.clear();
    std::string line;
   
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string key, value;
      
        if (std::getline(ss, key, ',') && std::getline(ss, value)) {
           
           
            m_requirements_cache[key] = value;
        }
    }
}



// Parser.cpp içindeki mevcut is_function_signature fonksiyonunu bununla değiştirin

bool Parser::is_function_signature(const std::string& line) {
    // 1. Satır başı ve sonundaki boşlukları temizle
    std::string trimmed_line = std::regex_replace(line, std::regex("^\\s+|\\s+$"), "");

    // 2. Yorum, preprocessor veya boş satırları en başta ele
    if (trimmed_line.empty() || trimmed_line.rfind("//", 0) == 0 || trimmed_line.rfind("/*", 0) == 0 || trimmed_line.rfind("#", 0) == 0) {
        return false;
    }

    // 3. Satırın sonunda noktalı virgül varsa, bu bir prototip veya çağrıdır.
    if (trimmed_line.back() == ';') {
        return false;
    }
    
    // 4. Parantezlerin varlığını ve sırasını kontrol et
    auto open_paren = trimmed_line.find('(');
    auto close_paren = trimmed_line.find(')');
    if (open_paren == std::string::npos || close_paren == std::string::npos || open_paren > close_paren) {
        return false;
    }

    // 5. 'if', 'while' gibi kontrol yapılarını ele
    std::smatch match;
    if (std::regex_search(trimmed_line, match, std::regex("^(if|while|for|switch)\\s*\\("))) {
        return false;
    }

    // 6. Son olarak, fonksiyon tanımına uyuyor mu diye regex ile kontrol et
    std::regex function_regex(
        "^[\\w\\s\\*&]+\\s+"          // Dönüş tipi (void, int, char*, unsigned int vb.)
        "([a-zA-Z_][a-zA-Z0-9_]*)"  // Fonksiyon adı
        "\\s*\\([^;]*\\)\\s*$"        // Parametreler
    );

    if (std::regex_match(trimmed_line, function_regex)) {
        // Fonksiyon adının bir C anahtar kelimesi olmadığını da kontrol edelim
        std::smatch name_match;
        if (std::regex_search(trimmed_line, name_match, std::regex("\\s+([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\("))) {
            if (is_keyword(name_match[1].str())) {
                return false;
            }
        }
        // Tüm kontrollerden geçti, bu bir fonksiyondur.
        return true;
    }

    // Hiçbir koşula uymuyorsa, fonksiyon değildir.
    return false;
}



std::optional<Parser::Function> Parser::parse_function_signature(const std::string& signature) {
    // Bu C kodunun mantığını std::string metotlarıyla yeniden yazıyoruz.
    size_t lparen_pos = signature.find('(');
    if (lparen_pos == std::string::npos) return std::nullopt;

    size_t rparen_pos = signature.rfind(')');
    if (rparen_pos == std::string::npos || rparen_pos < lparen_pos) return std::nullopt;
    
    // Fonksiyon ismini bul
    size_t name_end = signature.find_last_not_of(" \t", lparen_pos - 1);
    if(name_end == std::string::npos) return std::nullopt;
    size_t name_start = signature.find_last_of(" \t*", name_end) + 1;
    std::string name = signature.substr(name_start, name_end - name_start + 1);

    // Dönüş tipini bul
    size_t return_type_end = signature.find_last_not_of(" \t", name_start - 1);
     if(return_type_end == std::string::npos) return std::nullopt;
    size_t return_type_start = 0; // Basitleştirilmiş varsayım
    std::string return_type = signature.substr(return_type_start, return_type_end - return_type_start + 1);

    // Anahtar kelimeleri ve boşlukları temizle
    size_t first_char = return_type.find_first_not_of(" \t");
    if(first_char != std::string::npos) return_type = return_type.substr(first_char);

    Function func;
    func.name = name;
    func.return_type = return_type;
    func.parameters = extract_parameters(signature);

    return func;
}


std::vector<std::string> Parser::extract_parameters(const std::string& signature) {
   
    std::vector<std::string> params;
    size_t start = signature.find('(');
    size_t end = signature.rfind(')');
    if (start == std::string::npos || end == std::string::npos) return params;

    std::string params_str = signature.substr(start + 1, end - start - 1);
    if(params_str.empty() || params_str.find_first_not_of(" \t") == std::string::npos) return params; 
    if(params_str == "void") return params;


    std::stringstream ss(params_str);
    std::string segment;

    while(std::getline(ss, segment, ',')) {
        std::stringstream segment_ss(segment);
        std::string last_word;
        std::string word;
        while(segment_ss >> word) {
          
            word.erase(std::remove(word.begin(), word.end(), '*'), word.end());
            word.erase(std::remove(word.begin(), word.end(), '&'), word.end());
            if(!word.empty()) {
                last_word = word;
            }
        }
        if(!last_word.empty() && !is_keyword(last_word)){
             params.push_back(last_word);
        }
    }
    return params;
}


bool Parser::is_keyword(const std::string& word) {
    static const std::unordered_map<std::string, bool> keywords = {
        {"int", true}, {"char", true}, {"double", true}, {"float", true},
        {"long", true}, {"short", true}, {"bool", true}, {"void", true},
        {"unsigned", true}, {"signed", true}, {"const", true}, {"volatile", true},
        {"static", true}, {"typename", true}, {"class", true}, {"struct", true}
    };
    return keywords.count(word) > 0;
}



Parser::CommentInfo Parser::extract_comments(const std::vector<std::string>& comment_lines) {
    CommentInfo info;
    std::string last_key;
    std::string current_value;

    for (const auto& line : comment_lines) {
        std::stringstream ss(line);
        std::string word;
        ss >> word; 

       
        size_t first_char_pos = line.find_first_not_of(" \t/*");
        if(first_char_pos == std::string::npos) continue;
        
        std::string clean_line = line.substr(first_char_pos);

        if (clean_line[0] == '@') {
            if (!last_key.empty()) {
                info[last_key] = current_value;
            }
            
            std::stringstream line_ss(clean_line);
            std::string tag;
            line_ss >> tag; //
            
            last_key = tag.substr(1); // 
            
            // @param için özel durum
            if (last_key == "param") {
                std::string param_name;
                line_ss >> param_name;
                last_key += " " + param_name;
            }
            
            std::getline(line_ss, current_value); 
          
            current_value.erase(0, current_value.find_first_not_of(" \t"));

        } else if (!last_key.empty()) {
            
            current_value += " " + clean_line;
        }
    }
    
    if (!last_key.empty()) {
        info[last_key] = current_value;
    }

    return info;
}


std::vector<Issue> Parser::compare_with_function(const CommentInfo& information, const Function& function) {
    std::vector<Issue> issues;

    // @brief etiketini kontrol et
    if (information.count("brief") == 0) {
        issues.push_back({function.name, "No @brief attribute."});
    }

    // @retval etiketini kontrol et
    if (function.return_type != "void") {
        if (information.count("retval") == 0) {
            issues.push_back({function.name, "No @retval attribute for non-void function."});
        }
    }

    // Parametreleri kontrol et
    for (const auto& param_name : function.parameters) {
        std::string param_key = "param " + param_name;
        if (information.count(param_key) == 0) {
            issues.push_back({function.name, "Missing @param for parameter '" + param_name + "'."});
        }
    }
    
    // Gereksinimi kontrol et
    if (information.count("req") > 0) {
        const std::string& req_value = information.at("req");
        if (!requirements_match(function.name, req_value)) {
            issues.push_back({function.name, "Requirement mismatch. Found: " + req_value});
        }
    } else {
        issues.push_back({function.name, "No @req attribute."});
    }

    return issues;
}


// Fonksiyon adı ve gereksinim numarasının eşleşip eşleşmediğini kontrol eder
bool Parser::requirements_match(const std::string& function_name, const std::string& requirement) {
    if (m_requirements_cache.count(function_name) > 0) {
        return m_requirements_cache.at(function_name) == requirement;
    }
    return false;
}