#ifndef FORM_HPP

# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const _name;
		int _gradeToSign;
		int _gradeToExecute;
		bool _isSigned;
	
	public:
		Form(const char* name, int gradeToSign, int gradeToExecute);
		~Form(void);

		Form(const Form &copy);
		Form &operator=(const Form& copy);

		void beSigned(const Bureaucrat& bureaucrat);
		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool getIsSigned(void) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif