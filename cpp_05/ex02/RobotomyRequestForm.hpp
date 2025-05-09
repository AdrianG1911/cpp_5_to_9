#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <string>
#include "AForm.hpp"  // Include the base class header

class RobotomyRequestForm : public AForm {   // Inherit from base class
private:
    std::string target;
public:
    RobotomyRequestForm();  // Default constructor
    RobotomyRequestForm(const RobotomyRequestForm &other);  // Copy constructor
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);  // Assignment operator
    ~RobotomyRequestForm();  // Destructor
    RobotomyRequestForm(std::string target);

    std::string getTarget() const;
    void exec() const;
};

#endif
