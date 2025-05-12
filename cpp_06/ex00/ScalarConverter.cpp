#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string &str)
{
    int type = get_type(str);

    switch (type)
    {
        case INVALID:
            std::cout << "Invalide input\n";
            break ;
        case CHAR:
            convert_char(str);
            break ;
        case INT:
            convert_int(str);
            break ;
        case FLOAT:
            convert_float(str);
            break ;
        case DOUBLE:
            convert_double(str);
            break ;
        case SPECIAL:
            convert_special(str);
            break ;
    }
}
