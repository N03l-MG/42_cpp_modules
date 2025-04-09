/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:49:08 by kixik             #+#    #+#             */
/*   Updated: 2025/04/04 14:52:35 by kixik            ###   ########.fr       */
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
