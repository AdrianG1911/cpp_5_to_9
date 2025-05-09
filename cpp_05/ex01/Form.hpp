#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

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
	Form(const std::string name, const int grade_to_sign, const int grade_to_execute);

	std::string getNam() const;
	bool		getSign() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void	beSigned(const Bureaucrat& b);
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif