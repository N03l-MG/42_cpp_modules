/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:08 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/07 15:55:42 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("John Doe", 1);
		Form form("Form A", 50, 100);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("Gunther Frager", 1);
		Form form("Form B", 50, 100);
		std::cout << bureaucrat << std::endl;
		std::cout << form << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
