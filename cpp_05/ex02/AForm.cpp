#include "AForm.hpp"

AForm::AForm() : name("form"), sign(false), grade_to_sign(40), grade_to_execute(90)
{
}

AForm::AForm(const AForm &other) : name(other.name), sign(other.sign), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

AForm::~AForm()
{
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute) 
: name(name), sign(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

std::string AForm::getNam() const
{
	return this->name;
}

bool AForm::getSign() const
{
	return this->sign;
}

int AForm::getGradeToSign() const
{
	return this->grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return this->grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->grade_to_sign)
		throw GradeTooLowException();
	else
		this->sign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error: Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Error: attmpted to execute unsigned form!";
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
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

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->sign == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	this->exec();
}