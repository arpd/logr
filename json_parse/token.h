#ifndef JSON_PARSE_TOKEN_H__
#define JSON_PARSE_TOKEN_H__
#include <string>
#include <map>
#include <regex>

namespace json_parse {
    class Token {
        public:
        enum tok_type {
            STRING,
            NUMBER,
            RBRACE,
            LBRACE,
            RBRACKET,
            LBRACKET,
            TRUE,
            FALSE,
            NULLVAL,
            COMMA,
            COLON,
            UNDEFINED,
        };
        private:
        tok_type type;
        bool valid;
        static const std::map<tok_type, std::regex* > regex_map;
        static const std::map<tok_type, const std::string* > token_strings;
        std::pair<int, int> source_location;
        std::string value;
        public:
        Token(const std::string&, int, int);
        Token(const std::string&, std::pair<int, int>);
        tok_type get_type();
        bool is_valid();
        const std::string& get_value();
        static const std::string* str_of_enum(tok_type);
        const std::pair<int, int>& get_source_loc();
        static bool is_type(tok_type, const std::string&);
        private:
        tok_type determine_type();
    };
};
#endif
