#include "token.h"
#include <iostream>

using namespace std;

int main() {
    json_parse::Token t_num("5.023 E+ 123", 0, 0);
    cout << *(json_parse::Token::str_of_enum(t_num.get_type())) << endl;
    json_parse::Token t_str("\"a cool string\"", 0, 0);
    cout << *(json_parse::Token::str_of_enum(t_str.get_type())) << endl;
    json_parse::Token t_true("{", 0, 0);
    cout << *(json_parse::Token::str_of_enum(t_true.get_type())) << endl;

}
