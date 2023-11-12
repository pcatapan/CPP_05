#include "Form.hpp"

Form::Form(const char* name, int gradeToSign, int gradeToExecute) : _name(name ? std::string(name) : "Default"), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form(void) {}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form &Form::operator=(const Form& copy)
{
	if (this == &copy)
		return (*this);
	
	this->_gradeToSign = copy._gradeToSign;
	this->_gradeToExecute = copy._gradeToExecute;
	this->_isSigned = copy._isSigned;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		bureaucrat.signForm(this->_isSigned, this->_name, "grade is too low");
		throw GradeTooLowException();

		return ;
	}
	this->_isSigned = true;

	bureaucrat.signForm(this->_isSigned, this->_name);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute() << ", is signed " << form.getIsSigned() << std::endl;
	return (os);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}