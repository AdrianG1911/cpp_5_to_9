#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern intern;
	try
	{
		Bureaucrat steve("Steve", 1);
		AForm* form = intern.makeForm("presidential pardon", "Bobby");
		if (form != NULL)
		{
			steve.signForm(*form);
			steve.executeForm(*form);
			Bureaucrat hilda("Hilda", 150);
			hilda.executeForm(*form);
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm* form = intern.makeForm("robotomy request", "healthy baby");
		if (form != NULL)
		{
			Bureaucrat robotman("robotman", 1);
			Bureaucrat robotbaby("robotbaby", 75);
			std::cout << *form << "\n";
			robotman.signForm(*form);
			robotman.executeForm(*form);
			robotbaby.executeForm(*form);
			delete form;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bobo("Bobo", 1);
		Bureaucrat ratman("ratman", 150);
		AForm* form = intern.makeForm("shrubbery creation", "shrubs.txt");
		if (form != NULL)
		{
			ratman.signForm(*form);
			bobo.signForm(*form);
			ratman.executeForm(*form);
			bobo.executeForm(*form);
			delete form;
		}
		AForm* form2 = intern.makeForm("not real", "target");
		if (form2 != NULL)
			delete form2;
			
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}