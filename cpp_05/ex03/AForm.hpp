#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				sign;
	const int			grade_to_sign;
	const int			grade_to_execute;
public:
	AForm();
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	AForm(const std::string name, const int grade_to_sign, const int grade_to_execute);
	
	virtual 
	std::string getNam() const;
	bool		getSign() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	virtual std::string getTarget() const = 0;

	void	beSigned(const Bureaucrat& b);

	void execute(Bureaucrat const & executor) const;
	virtual void exec() const = 0;

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

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif