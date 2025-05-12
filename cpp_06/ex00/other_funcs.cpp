#include <string>
#include <iostream>
#include <cstdlib>
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
	long	c;

	c = str[0];
	if (len > 1)
		c = str[1];
	std::cout << "char: ";
	if (c > 127 || c < 0)
		std::cout << "impossible\n";
	else if (ft_isprintable(c) == true)
		std::cout << static_cast<char>(c) << "\n";
	else
		std::cout  << "non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n"; 
}

void	convert_int(const std::string &str)
{
	long	i;

	i = std::atol(str.c_str());
	std::cout << "char: ";
	if (i > 127 || i < 0)
		std::cout << "impossible\n";
	else if (ft_isprintable(i) == true)
		std::cout << static_cast<char>(i) << "\n";
	else
		std::cout  << "non displayable\n";
	std::cout << "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << "f\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void convert_float(const std::string &str)
{
	double bf;
	float f;
	long  fl;

	bf = atof(str.c_str());
	f = static_cast<float>(bf);
	bf = static_cast<double>(f);
	fl = static_cast<long>(f);
	std::cout << "char: ";
	if (fl > 127 || fl < 0)
		std::cout << "impossible\n";
	else if (ft_isprintable(fl) == true)
		std::cout << static_cast<char>(fl) << "\n";
	else
		std::cout  << "non displayable\n";
	std::cout << "int: ";
	if (fl > INT_MAX || fl < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << fl << "\n";
	std::cout << "float: ";
	if (f > FLT_MAX || f < FLT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << f << "f\n";
	std::cout << "double: ";
	if (bf > DBL_MAX || bf < DBL_MIN)
		std::cout << "impossible\n";
	else
		std::cout << bf << "\n";
}


void convert_double(const std::string &str)
{
	double db;
	float f;
	long  l;

	db = atof(str.c_str());
	f = static_cast<float>(db);
	l = static_cast<long>(f);
	std::cout << "char: ";
	if (l > 127 || l < 0)
		std::cout << "impossible\n";
	else if (ft_isprintable(l) == true)
		std::cout << static_cast<char>(l) << "\n";
	else
		std::cout  << "non displayable\n";
	std::cout << "int: ";
	if (l > INT_MAX || l < INT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << l << "\n";
	std::cout << "float: ";
	if (f > FLT_MAX || f < FLT_MIN)
		std::cout << "impossible\n";
	else
		std::cout << f << "f\n";
	std::cout << "double: ";
	if (db > DBL_MAX || db < DBL_MIN)
		std::cout << "impossible\n";
	else
		std::cout << db << "\n";
}

void	convert_special(const std::string &str)
{
	int	type;

	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	if (str[0] == 'n')
		type = 0;
	if (str[0] == '+')
		type = 1;
	if (str[0] == '-')
		type = 2;
	std::cout << "float: ";
	switch (type)
	{
		case 0:
			std::cout << "nan";
			break ;
		case 1:
			std::cout << "+inf";
			break ;
		case 2:
			std::cout << "-inf";
			break ;
	}
	std::cout << "f\n";

	std::cout << "double: ";
	switch (type)
	{
		case 0:
			std::cout << "nan";
			break ;
		case 1:
			std::cout << "+inf";
			break ;
		case 2:
			std::cout << "-inf";
			break ;
	}
	std::cout << "\n";
}

int	get_type(const std::string& str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf") return SPECIAL;
    if (str == "-inf" || str == "+inf" || str == "nan") return SPECIAL;

	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return CHAR;
	if (str[str.length() - 1] == 'f' && str.find('.') != std::string::npos)
	{
		int	isfloat = 1;
		int	fs = 0;
		int	dots = 0;
		size_t	i = 0;
		if ((str[i] == '-' || str[i] == '+') && str.length() > 1)
			i++;
		while (i < str.length())
		{
			if (str[i] == 'f')
				fs++;
			if (str[i] == '.')
				dots++;
			if (std::isdigit(str[i]) == false && str[i] != '.' && str[i] != 'f')
				isfloat = 0;
			if (fs > 1 || dots > 1)
				isfloat = 0;
			i++;
		}
		if (isfloat == 0)
			return INVALID;
		return FLOAT;
	}
	size_t	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str.length() > 1)
		i++;
	int	isdouble = 1;
	int	isint = 1;
	int	dots = 0;
	while (i < str.length())
	{
		if (str[i] == '.')
				dots++;
		if (std::isdigit(str[i]) == false && str[i] != '.')
		{
			isint = 0;
			isdouble = 0;
		}
		if (dots > 0)
			isint = 0;
		if (dots > 1)
			isdouble = 0;
		i++;
	}
	if (isint == 1)
		return INT;
	if (isdouble == 1)
		return DOUBLE;
	return (INVALID);
}