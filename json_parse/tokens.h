#ifndef JSON_PARSE_TOKEN_H__
#define JSON_PARSE_TOKEN_H__
#include <string>

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
            NULL,
            COMMA,
        };
        private:
        tok_type type;
        bool valid;
        std::string value;
        public:
        Token(const std::string& value);
        tok_type get_type() const;
        bool is_valid() const;
        const std::string& get_value() const;
    }
}
#endif
