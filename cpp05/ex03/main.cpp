/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:08 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/09 14:00:11 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "TextFormat.hpp"

int main()
{
	std::cout << BOLD UNDERLINE CYAN "Form creation test:" RESET << std::endl;
	{
		Intern dave;
		Bureaucrat obama("Obama", 1);
		AForm *createdForm;
		std::cout << std::endl;

		createdForm = dave.makeForm("presidential pardon", "Waluigi");
		std::cout << std::endl;

		obama.signForm(*createdForm);
		obama.executeForm(*createdForm);
		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
			obama.decrementGrade();
		obama.executeForm(*createdForm);
		obama.signForm(*createdForm);
		std::cout << std::endl;

		delete createdForm;
	}
	std::cout << std::endl;
	std::cout << BOLD UNDERLINE CYAN "Invalid form test:" RESET << std::endl;
	{
		Intern dave;
		Bureaucrat obama("Obama", 150);
		AForm *createdForm;
		std::cout << std::endl;

		try {
			createdForm = dave.makeForm("not a form name", "who cares");
			obama.signForm(*createdForm);
			obama.executeForm(*createdForm);
			delete createdForm;
		} catch (Intern::FormNotFoundException &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
