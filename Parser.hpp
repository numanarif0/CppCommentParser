#ifndef CMT_PARSER_PARSER_HPP
#define CMT_PARSER_PARSER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <optional>

/*   İleride kullanılabilir 
enum class ParseResult {
    IssueFound,
    NoIssue,
    ParseError
};
*/

struct Issue {
    std::string function_name;
    std::string issue_value;
};

class Parser {
public:
    
    std::vector<Issue> parse_file(const std::string& file_path, const std::string& requirements_path);

private:
    

    
    struct Function {
        std::string name;
        std::string return_type;
        std::vector<std::string> parameters;
    };

   
    using CommentInfo = std::unordered_map<std::string, std::string>;


    std::unordered_map<std::string, std::string> m_requirements_cache;

  
    void cache_requirements(const std::string& requirements_path);
    CommentInfo extract_comments(const std::vector<std::string>& comment_lines);
    std::optional<Function> parse_function_signature(const std::string& signature);
    std::vector<std::string> extract_parameters(const std::string& signature);
    bool is_function_signature(const std::string& line);
    bool is_keyword(const std::string& word);
    bool requirements_match(const std::string& function_name, const std::string& requirement);
    std::vector<Issue> compare_with_function(const CommentInfo& information, const Function& function);
};

#endif  