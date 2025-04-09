/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:08 by kixik             #+#    #+#             */
/*   Updated: 2025/04/07 15:55:42 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "TextFormat.hpp"

int main()
{
	std::cout << BOLD UNDERLINE CYAN "Succesful tests:" RESET << std::endl;
	{
		Bureaucrat b1("John Doe", 1);
		Bureaucrat b2("Gunther Frager", 45);
		Bureaucrat b3("Misco Jones", 100);
		std::cout << std::endl;

		PresidentialPardonForm form1("Dan Hentshel");
		RobotomyRequestForm form2("Clap Trap");
		ShrubberyCreationForm form3("Plantpot");
		std::cout << std::endl;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << std::endl;

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
		std::cout << std::endl;

		b1.signForm(form1);
		b2.signForm(form2);
		b3.signForm(form3);
		std::cout << std::endl;

		b1.executeForm(form1);
		b2.executeForm(form2);
		b3.executeForm(form3);
		std::cout << std::endl;

		b1.executeForm(form2); // fails 50% of the time
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD UNDERLINE CYAN "Grade error tests:" RESET << std::endl;
	{
		try {
			Bureaucrat b1("John Doe", 1);
			Bureaucrat b2("Gunther Frager", 50);
			Bureaucrat b3("Misco Jones", 150);
			std::cout << std::endl;

			PresidentialPardonForm form1("Dan Hentshel");
			RobotomyRequestForm form2("Clap Trap");
			ShrubberyCreationForm form3("Plantpot");
			std::cout << std::endl;

			std::cout << b1 << std::endl;
			std::cout << b2 << std::endl;
			std::cout << b3 << std::endl;
			std::cout << std::endl;

			b1.signForm(form1);
			b2.signForm(form2);
			b3.signForm(form3);
			std::cout << std::endl;

			b1.executeForm(form1);
			b2.executeForm(form2);
			b3.executeForm(form3);
			std::cout << std::endl;

			b3.decrementGrade();
			b1.incrementGrade();
			std::cout << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		// Constructing Bureaucrat with invalid grade
		try {
			Bureaucrat b("Mx. Perfect", 0);
			std::cout << b << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << BOLD UNDERLINE CYAN "Sign and execute error tests:" RESET << std::endl;
	{
		Bureaucrat b("Overpayed office worker", 46);
		RobotomyRequestForm f("Citizen");
		std::cout << std::endl;

		b.executeForm(f);
		b.signForm(f);
		b.signForm(f);
		b.executeForm(f);
		b.incrementGrade();
		b.executeForm(f);
		std::cout << std::endl;
	}
	return 0;
}
