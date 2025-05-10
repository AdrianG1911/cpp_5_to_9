#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#define INT_MAX std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define INT_MAX std::numeric_limits<float>::min()
#define INT_MAX std::numeric_limits<float>::max()
#define INT_MAX std::numeric_limits<double>::min()
#define INT_MAX std::numeric_limits<double>::max()


#include <iostream>

class ScalarConverter {
public:
    ScalarConverter();                            // Default constructor
    ScalarConverter(const ScalarConverter& other);  // Copy constructor
    ScalarConverter& operator=(const ScalarConverter& other); // Copy assignment
    ~ScalarConverter();                           // Destructor

    static void convert(const std::string& str);

};

bool ft_isprintable(char c);
void convert_char(const std::string &str);

#endif // SCALARCONVERTER_HPP
