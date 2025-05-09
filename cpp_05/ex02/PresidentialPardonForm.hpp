#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <string>
#include "AForm.hpp"  // Include the base class header

class PresidentialPardonForm : public AForm {   // Inherit from base class
private:
    std::string target;
public:
    PresidentialPardonForm();  // Default constructor
    PresidentialPardonForm(const PresidentialPardonForm &other);  // Copy constructor
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);  // Assignment operator
    ~PresidentialPardonForm();  // Destructor
    PresidentialPardonForm(std::string target);
    
    std::string getTarget() const;
    void exec() const;
};

#endif
