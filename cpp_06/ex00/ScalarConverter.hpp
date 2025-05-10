#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>

class ScalarConverter {
public:
    ScalarConverter();                            // Default constructor
    ScalarConverter(const ScalarConverter& other);  // Copy constructor
    ScalarConverter& operator=(const ScalarConverter& other); // Copy assignment
    ~ScalarConverter();                           // Destructor


};

#endif // SCALARCONVERTER_HPP
