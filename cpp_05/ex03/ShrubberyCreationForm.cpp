#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), target("shrub.txt")
{  // Call base class constructor
    // Constructor implementation
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {  // Call base class copy constructor
    *this = other;  // Call assignment operator
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {  // Self-assignment check
        AForm::operator=(other);  // Copy base class data
        // Copy derived class data here if needed
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // Destructor implementation
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("shrubbery creation", 145, 137), target(target)
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::exec() const
{
    std::ofstream file(this->target.c_str());
    if (!file.is_open())
    {
        std::cerr << "error: failed to open file\n";
        std::exit(1);
    }
    for (int i = 0; i < 5; ++i)
    {
        file << "    *    " << "\n";
        file << "   AAA   " << "\n";
        file << "  AAAAA  " << "\n";
        file << " AAAAAAA " << "\n";
        file << "AAAAAAAAA" << "\n";
        file << "    |    " << "\n";
    }
    file.close();
}