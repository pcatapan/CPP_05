#include "AForm.hpp"

AForm::AForm(const char* name, int gradeToSign, int gradeToExecute) : _name(name ? std::string(name) : "Default"), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm(void) {}

AForm::AForm(const AForm &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

AForm &AForm::operator=(const AForm& copy)
{
	if (this == &copy)
		return (*this);
	
	this->_gradeToSign = copy._gradeToSign;
	this->_gradeToExecute = copy._gradeToExecute;
	this->_isSigned = copy._isSigned;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		bureaucrat.signAForm(this->_isSigned, this->_name, "grade is too low");
		throw GradeTooLowException();

		return ;
	}
	this->_isSigned = true;

	bureaucrat.signAForm(this->_isSigned, this->_name);
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
	{
		executor.executeAForm(this->_isSigned, this->_name, "grade is too low");
		throw GradeTooLowException();

		return ;
	}
	this->action();
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm " << AForm.getName() << ", grade to sign " << AForm.getGradeToSign() << ", grade to execute " << AForm.getGradeToExecute() << ", is signed " << AForm.getIsSigned() << std::endl;
	return (os);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}