#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

class Intern {
public:
    Intern();                            // Default constructor
    Intern(const Intern& other);  // Copy constructor
    Intern& operator=(const Intern& other); // Copy assignment
    ~Intern();                           // Destructor

    AForm* makeForm(const std::string& form_type, const std::string& target_name) const;
};

#endif // INTERN_HPP
