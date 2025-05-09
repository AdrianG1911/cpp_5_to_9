#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
 : AForm("robotomy request", 72, 45), target("human")
{  // Call base class constructor
    // Constructor implementation
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {  // Call base class copy constructor
    *this = other;  // Call assignment operator
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {  // Self-assignment check
        AForm::operator=(other);  // Copy base class data
        // Copy derived class data here if needed
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    // Destructor implementation
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("robotomy request", 72, 45), target(target)
{
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::exec() const
{
    std::srand(std::time(0));
    if (rand() % 2 == 0)
    {
        std::cout << this->target << " has been robotomized succeffully\n";
    }
    else
    {
        std::cout << "Robotomy failed on target, " << this->target << "\n";
    }
}