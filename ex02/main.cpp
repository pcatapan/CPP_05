#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


int main(void)
{
	// Seed the random number generator with the current time
	std::srand(std::time(NULL));

	std::cout << "======(ShrubberyCreationForm)======" << std::endl;
	std::cout << "Required grades: sign 145, exec 137" << std::endl;
	std::cout << std::endl;

	Bureaucrat bur1("bur11", 1);
	Bureaucrat bur140("bur12", 140);
	Bureaucrat bur150("bur13", 150);

	ShrubberyCreationForm f("form");
	ShrubberyCreationForm f2("test2");

	// form not signed
	try {
		std::cout << f << std::endl;
		f.execute(bur1);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// grade too low to sign
	try {
		std::cout << bur150 << std::endl;
		std::cout << f << std::endl;
		f.beSigned(bur150);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// grade too low to execute
	try {
		std::cout << bur140 << std::endl;
		std::cout << f << std::endl;
		f.beSigned(bur140);
		bur140.executeForm(f);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// should work
	try {
		std::cout << bur1 << std::endl;
		f.execute(bur1);
		f2.beSigned(bur1);
		bur1.executeForm(f2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "======(RobotomyRequestForm)======" << std::endl;
	std::cout << "Required grades: sign 72, exec 45" << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat bur2("bur2", 2);
	Bureaucrat bur70("bur22", 70);
	Bureaucrat bur100("bur23", 100);

	RobotomyRequestForm b("Oscar");
	RobotomyRequestForm b2("Robert");

	// form not signed
	try {
		std::cout << b << std::endl;
		b.execute(bur2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	// should work
	try {
		std::cout << bur2 << std::endl;
		b.execute(bur2);
		b2.beSigned(bur2);
		bur2.executeForm(b2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "======(PresidentialPardonForm)======" << std::endl;
	std::cout << "Required grades: sign 25, exec 5" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Bureaucrat bur3("bur3", 3);
	Bureaucrat bur20("bur32", 20);
	Bureaucrat bur30("bur33", 30);

	PresidentialPardonForm c("Luffy");
	PresidentialPardonForm c2("Peter");

	std::cout << std::endl;

	// should work
	try {
		std::cout << bur3 << std::endl;
		c.execute(bur3);
		c2.beSigned(bur3);
		bur3.executeForm(c2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
