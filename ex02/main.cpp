/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:14:04 by pcatapan          #+#    #+#             */
/*   Updated: 2023/11/01 23:20:44 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("B1", 1);
		Bureaucrat b2("B2", 150);
		AForm f1("F1", 1, 1);
		std::cout << f1;

		f1.beSigned(b1);
		std::cout << f1;

		AForm f2 = f1;
		f2.beSigned(b2);
		std::cout << f2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}