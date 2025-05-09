#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat steve("Steve", 75);
		Form form("form", 60, 75);
		std::cout << form << "\n";
		steve.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form form("wow", 1, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bobo("Bobo", 75);
		Form form("new form", 100, 90);
		std::cout << form << "\n";
		bobo.signForm(form);
		std::cout << form << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}