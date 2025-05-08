#include "form.hpp"

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
