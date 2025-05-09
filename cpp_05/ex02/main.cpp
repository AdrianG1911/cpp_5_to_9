#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main()
{
	try
	{
		Bureaucrat steve("Steve", 1);
		PresidentialPardonForm form("Bobby");
		std::cout << form << "\n";
		steve.signForm(form);
		steve.executeForm(form);
		Bureaucrat hilda("Hilda", 150);
		hilda.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat robotman("robotman", 1);
		Bureaucrat robotbaby("robotbaby", 75);

		RobotomyRequestForm form("healthy baby");
		std::cout << form << "\n";
		robotman.signForm(form);
		robotman.executeForm(form);
		robotbaby.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bobo("Bobo", 1);
		Bureaucrat ratman("ratman", 150);
		ShrubberyCreationForm form("shrubs.txt");
		ratman.signForm(form);
		bobo.signForm(form);
		ratman.executeForm(form);
		bobo.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}