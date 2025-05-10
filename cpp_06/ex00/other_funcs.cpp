#include <string>
#include <iostream>
#include "ScalarConverter.hpp"

bool ft_isprintable(long c)
{
	if (c < 32 || c > 126)
		return (false);
	return (true);
}

void	convert_char(const std::string& str)
{
	int 	len = str.length();
	char	c;

	c = str[0];
	if (len > 1)
		c = str[1];
	if (ft_isprintable(c) == true)
		std::cout << "char: " << c << "\n";
	else
		std::cout << "char: " << "non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n"; 
}

void	convert_int(const std::string &str)
{
	long	i;

	i = std::atol(str.c_str());
	if (ft_isprintable(i) == true)
		std::cout << "char: " << i << "\n";
	else
		std::cout << "Non displayable\n";
	if (i > )
	
}