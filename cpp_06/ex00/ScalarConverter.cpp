#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this != &other)
        ;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::convert(const std::string &str)
{
    convert_char(str);
}
