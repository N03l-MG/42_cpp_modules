/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:08 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/09 14:43:14 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("John Doe", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		Bureaucrat bureaucrat("Jane Doe", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
