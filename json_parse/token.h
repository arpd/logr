#ifndef JSON_PARSE_TOKEN_H__
#define JSON_PARSE_TOKEN_H__
#include <string>

namespace json_parse {
    class Token {
        public:
        enum tok_type {
            STRING,
            NUMBER,
            NUMBER_POINT,    // <digits> . <digits>
            NUMBER_EXPONENT, // e[+-] | E[+-]
            RBRACE,
            LBRACE,
            RBRACKET,
            LBRACKET,
            TRUE,
            FALSE,
            NULL,
            COMMA,
            UNDEFINED,
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
        private:
        tok_type determine_type();
        bool     determine_if_valid();
        bool     is_number(const std::string& value);
        struct source_location { int line, col; }
    };
};
#endif
