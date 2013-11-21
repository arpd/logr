#include <cctype> // for isdigit
#include "token.h"

namespace json_parse {
    Token::Token(const std::string& value) : value(value) {
        type = determine_type();
        valid = deteremine_if_valid();
    }

    Token::tok_type Token::determine_type() {
        /* process this->value to find out which `tok_type` we should assign */
        /* is it a string? */
        if (value.front() == '"' && value.back() == '"')
            return Token::tok_type.STRING;
        /* is it a number? */
        else if (Token::is_number(value))
            return Token::tok_type.NUMBER;
    }

    bool Token::is_number(const std::string& value) {
        /*
         * 123
         * 123.123
         * 123 E+ 123
         * 123.123 E+ 123
         */
        // sign
        // fraction
        // exponent
        int index = 0;
        if (value.at(index) == '-')
            ++index;
        for (index; index < value.length(); ++index) {
            
        }

        return true;
    }
};
