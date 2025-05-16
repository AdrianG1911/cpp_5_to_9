#include "RPN.hpp"
#include <exception>
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
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