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
    int type = getType(str);

    switch (type)
    {
        case INVALID:
            std::cout << "Invalide input\n";
            break ;
        case CHAR:
            convertChar(str);
            break ;
        case INT:
            convertInt(str);
            break ;
        case FLOAT:
            convertFloat(str);
            break ;
        case DOUBLE:
            convertDouble(str);
            break ;
        case SPECIAL:
            convertSpecial(str);
            break ;
    }
}
