#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				sign;
	const int			grade_to_sign;
	const int			grade_to_execute;
public:
	Form();
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

};

#endif