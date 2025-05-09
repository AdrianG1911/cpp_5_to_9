#include "Form.hpp"

Form::Form() : name("form"), sign(false), grade_to_sign(40), grade_to_execute(90)
{
}

Form::Form(const Form &other) : name(other.name), sign(other.sign), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

Form::~Form()
{
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute) 
: name(name), sign(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

std::string Form::getNam() const
{
	return this->name;
}

bool Form::getSign() const
{
	return this->sign;
}

int Form::getGradeToSign() const
{
	return this->grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->grade_to_sign)
		throw GradeTooLowException();
	else
		this->sign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade is too low!";
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	o << "Form name: " << form.getNam();
	o << ", is signed: ";
	if (form.getSign() == true)
		o << "true";
	else
		o << "false";
	o << ", grade to sign: " << form.getGradeToSign();
	o << ", grade to execute: " << form.getGradeToExecute();
	return o;
}