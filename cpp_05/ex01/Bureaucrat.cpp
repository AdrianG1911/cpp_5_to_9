#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Roy"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increment()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade is too low!";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &Bureaucrat)
{
	o << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (o);
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getNam() << "\n";
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << form.getNam() \
		<< " because " << e.what() << '\n';
	}
}