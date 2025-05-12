#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <limits>

#define INT_MIN std::numeric_limits<int>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define FLT_MIN -std::numeric_limits<float>::max()
#define FLT_MAX std::numeric_limits<float>::max()
#define DBL_MIN -std::numeric_limits<double>::max()
#define DBL_MAX std::numeric_limits<double>::max()

#define SPECIAL 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define INVALID 5


#include <iostream>

class ScalarConverter {
private:
    ScalarConverter();                            // Default constructor
    ScalarConverter(const ScalarConverter& other);  // Copy constructor
    ScalarConverter& operator=(const ScalarConverter& other); // Copy assignment
    ~ScalarConverter();                           // Destructor
public:
    static void convert(const std::string& str);

};

bool ft_isprintable(long c);
void convert_char(const std::string &str);
void convert_int(const std::string &str);
void convert_float(const std::string &str);
void convert_double(const std::string &str);
void convert_special(const std::string &str);
int	get_type(const std::string& str);

#endif // SCALARCONVERTER_HPP
