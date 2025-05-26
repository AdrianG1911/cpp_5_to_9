#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	if (std::string(argv[1]).length() < 2 || std::string(argv[1]).length() % 2 != 1)
	{
		std::cerr << "invalid input" << std::endl;
		return (1);
	}
	try
	{
		int ans = rpn(argv);
		std::cout << ans << std::endl;
	}
	catch(const std::exception& e)
	{
		return (1);
	}
	return (0);
}