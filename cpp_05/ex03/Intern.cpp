#include "Intern.hpp"


Intern::Intern() {

}

Intern::Intern(const Intern& other) {

    *this = other;
}

Intern& Intern::operator=(const Intern& other) {

    if (this != &other) {
        
        // Copy fields here
    }
    return *this;
}

Intern::~Intern() {

}

AForm *Intern::makeForm(const std::string &form_type, const std::string &target_name) const
{
	const std::string forms_types[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm *form = NULL;
    int i;
    for (i = 0; i < 3; ++i)
    {
        if (forms_types[i] == form_type)
            break ;
    }
    switch (i)
    {
    case 0:
        form = new RobotomyRequestForm(target_name);
        break;
    case 1:
        form = new PresidentialPardonForm(target_name);
        break;
    case 2:
        form = new ShrubberyCreationForm(target_name);
        break;
    default:
        break;
    }
    if (form == NULL)
        std::cerr << "Error: form does not exist\n";
    else
        std::cout << "Intern creates " << *form << "\n";
    return (form);
}
