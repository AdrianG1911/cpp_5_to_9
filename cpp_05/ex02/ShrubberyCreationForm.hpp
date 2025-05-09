#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <string>
#include <fstream>
#include "AForm.hpp"  // Include the base class header

class ShrubberyCreationForm : public AForm {   // Inherit from base class
private:
    std::string target;
public:
    ShrubberyCreationForm();  // Default constructor
    ShrubberyCreationForm(const ShrubberyCreationForm &other);  // Copy constructor
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);  // Assignment operator
    ~ShrubberyCreationForm();  // Destructor
    ShrubberyCreationForm(std::string target);
    std::string getTarget() const;
    void exec() const;
};

#endif
