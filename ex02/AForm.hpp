#ifndef AAForm_HPP

# define AAForm_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class AAForm
{
	private:
		std::string const _name;
		int _gradeToSign;
		int _gradeToExecute;
		bool _isSigned;
	
	public:
		AAForm(const char* name, int gradeToSign, int gradeToExecute);
		~AAForm(void);

		AForm(const AForm &copy);
		AForm &operator=(const AForm& copy);

		void beSigned(const Bureaucrat& bureaucrat);
		std::string getName(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		bool getIsSigned(void) const;

		void execute(const Bureaucrat& executor) const;

		virtual void action(void) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif