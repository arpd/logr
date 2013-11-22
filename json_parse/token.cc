#include <cctype> // for isdigit
#include "token.h"

namespace json_parse {
    const std::map<Token::tok_type, std::regex* > Token::regex_map =
    {
        { Token::tok_type::STRING,   new std::regex(R"!--(".*")!--") },
        { Token::tok_type::NUMBER,   new std::regex(
                R"!--(-?(?:0|[1-9]\d*)(?:\.\d+)?(?:[eE][+-]?\d+)?)!--") },
        { Token::tok_type::LBRACE,   new std::regex(R"!--(\{)!--") },
        { Token::tok_type::RBRACE,   new std::regex(R"!--(\})!--") },
        { Token::tok_type::LBRACKET, new std::regex(R"!--(\[)!--") },
        { Token::tok_type::RBRACKET, new std::regex(R"!--(\])!--") },
        { Token::tok_type::TRUE,     new std::regex(R"!--(true)!--") },
        { Token::tok_type::FALSE,    new std::regex(R"!--(false)!--") },
        { Token::tok_type::NULLVAL,  new std::regex(R"!--(null)!--") },
        { Token::tok_type::COMMA,    new std::regex(R"!--(,)!--") },
    };
    const std::map<Token::tok_type, const std::string* > Token::token_strings =
    {
        { Token::tok_type::STRING,   new std::string("string") },
        { Token::tok_type::NUMBER,   new std::string("number") },
        { Token::tok_type::LBRACE,   new std::string("object-begin") },
        { Token::tok_type::RBRACE,   new std::string("object-end") },
        { Token::tok_type::LBRACKET, new std::string("array-begin") },
        { Token::tok_type::RBRACKET, new std::string("array-end") },
        { Token::tok_type::TRUE,     new std::string("true") },
        { Token::tok_type::FALSE,    new std::string("false") },
        { Token::tok_type::NULLVAL,  new std::string("null") },
        { Token::tok_type::COMMA,    new std::string("comma") },
    };

    const std::pair<int, int>& Token::get_source_loc() { return source_location; }
    const std::string& Token::get_value() { return value; }
    Token::tok_type Token::get_type() { return type; }
    bool Token::is_valid() { return type != tok_type::UNDEFINED; }

    Token::Token(const std::string& value, std::pair<int, int> loc) : value(value) {
        Token::Token(value, loc.first, loc.second);
    }
    Token::Token(const std::string& value, int line, int col) : value(value) {
        type = determine_type();
        valid = type == Token::tok_type::UNDEFINED ? false : true;
        source_location.first  = line;
        source_location.second = col;
    }

    Token::tok_type Token::determine_type() {
        /* process this->value to find out which `tok_type` we should assign */
        /* is it a string? */
        for (auto tok_regex_pair : Token::regex_map) {
            if (std::regex_search(value, *tok_regex_pair.second))
                return tok_regex_pair.first;
        }

        return Token::tok_type::UNDEFINED;
    }

    const std::string* Token::str_of_enum(Token::tok_type type) {
        auto found = Token::token_strings.find(type);
        return found->second;
    }

    bool Token::is_type(Token::tok_type type, const std::string& val) {
        Token::Token t(val, 0, 0);
        return t.is_valid();
    }
};
