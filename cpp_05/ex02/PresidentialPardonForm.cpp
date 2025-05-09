#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() \
: AForm("presidential pardon", 25, 5), target("papa francisco")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {  // Call base class copy constructor
    *this = other;  // Call assignment operator
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {  // Self-assignment check
        AForm::operator=(other);  // Copy base class data
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    // Destructor implementation
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
: AForm("presidential pardon", 25, 5), target(target)
{
}

std::string PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::exec() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
}

