#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;
public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat(const std::string name, int grade);

	std::string getName() const;
	int	getGrade() const;

	void increment();
	void decrement();

	void signForm(Form& form) const;

	//exception classes
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

std::ostream& operator<<(std::ostream& o, const Bureaucrat& Bureaucrat);


#endif