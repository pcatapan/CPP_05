#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	private:
		std::string const _name;
		int	_grade;

	public:
		Bureaucrat(const char* name, int grade = 150);
		~Bureaucrat(void);

		Bureaucrat(const Bureaucrat &);
		Bureaucrat &operator=(const Bureaucrat& copy);

		const std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif