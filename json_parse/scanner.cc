#include "scanner.h"
#include <iostream>
#include <sstream>
#include <cctype>

namespace json_parse {

    bool Scanner::get_char(char* next) {
        do {
            next = in_stream.get();
            ++chars_read;
            if (*next == '\n') {
                ++lines_read;
                chars_read = 0;
            }
        } while (std::isspace(*next));
        if (std::ios::eofbit(in_stream) || std::ios::failbit(in_stream))
            return false;
    }

    /* TODO: Pull regex checking out of token so it can be used here (too?) */

    /*
    Scanner::Scanner(std::istream& in_stream)
        : in_stream(in_stream), lines_read(0) { }

    Token* Scanner::next_token() {
        char* c = NULL;
        char last_char;
        std::ostringstream ss;
        c = get_char();

        // is it a string?
        if (*c == '"') {
            bool cont;
            do {
                ss << *c;
                last_char = c;
                c = get_char();
                cont = (*c != '"') && last_char != '\\';
            } while (cont);
            return new Token(ss.str(), lines_read, chars_read);
        }
        // is it a number?
        else if (std::isdigit(*c)) {
            bool cont;
            short periods = 0;
            do {
                ss << *c;
                last_char = c;
                c = get_char();
                if (*c == '.')
                    ++periods;
                cont = std::isdigit(*c) && periods <= 1;
            } while (cont);
            return new Token(ss.str(), lines_read, chars_read);
        }
        // is it true?
        else if (*c == 't') {
            c = next_char();
        }
        switch(*c) {
            case '{':
            case '}':
            case '[':
            case ']':
            case ',':
            case ':':
                return new Token(ss.str(), lines_read, chars_read); break;
            default:
                // TODO: error
                return new Token(ss.str(), lines_read, chars_read); break;
        }
    }
    */ 

    Token* Scanner::get_token() {

    }

    Token* Scanner::peek() {
    }
};
