#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat steve("Steve", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat sato("Sato", 2);
		Bureaucrat sato2 = sato;
		std::cout << sato2 << "\n";
		sato.increment();
		std::cout << sato << "\n";
		sato.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bobo("Bobo", 75);
		std::cout << bobo << "\n";
		Bureaucrat lobo("Lobo", 150);
		bobo = lobo;
		std::cout << bobo << "\n";
		bobo.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}