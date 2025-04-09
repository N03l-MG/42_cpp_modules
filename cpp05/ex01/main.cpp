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
#include "Form.hpp"
#include "TextFormat.hpp"

int main()
{
	std::cout << CYAN UNDERLINE "Bureaucrat and Form Test:" RESET << std::endl;
	try {
		Bureaucrat bureaucrat("John Doe", 2);
		Form form("Form A", 1, 100);
		std::cout << std::endl;

		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		std::cout << std::endl;

		bureaucrat.signForm(form);
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.incrementGrade();
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << CYAN UNDERLINE "Signing tests:" RESET << std::endl;
	try {
		Bureaucrat bureaucrat("Gunther Frager", 1);
		Form form("Form B", 50, 100);
		std::cout << std::endl;

		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;
		std::cout << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
