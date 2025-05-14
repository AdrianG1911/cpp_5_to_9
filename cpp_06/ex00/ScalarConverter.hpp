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

bool ftIsprintable(long c);
void convertChar(const std::string &str);
void convertInt(const std::string &str);
void convertFloat(const std::string &str);
void convertDouble(const std::string &str);
void convertSpecial(const std::string &str);
int	getType(const std::string& str);

#endif // SCALARCONVERTER_HPP
