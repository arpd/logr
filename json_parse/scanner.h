#ifndef JSON_PARSE_SCANNER_H__
#define JSON_PARSE_SCANNER_H__
#include "token.h"

namespace json_parse {
    class Scanner {
        private:
        int lines_read; // count of '\n' characters encountered
        int chars_read; // resets every newline
        std::istream& in_stream;
        Token* current_token;
        bool get_char(char*);
        public:
        Scanner(const Scanner&) = delete;
        Scanner(const std::istream&);
        Token* get_token();
        Token* peek();
        private:
        Token* next_token();
    };
};

#endif
