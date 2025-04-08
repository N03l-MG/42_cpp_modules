/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:50:51 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/04 15:48:48 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << BOLD GREEN "Default Bureaucrat instance constructed." RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), grade(src.getGrade())
{
	std::cout << BOLD GREEN "Bureaucrat instance copy-constructed." RESET << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->grade = src.getGrade();
	// Note: name is const and cannot be reassigned
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD MAGENTA "Bureaucrat instance destroyed." RESET << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << BOLD GREEN "Bureaucrat " << name << " constructed." RESET << std::endl;
}

// Getters
const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

// Grade manipulation methods
void Bureaucrat::incrementGrade()
{
	std::cout << BLUE "Incrementing " << name << "'s grade..." RESET << std::endl;
	if (grade <= 1)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade()
{
	std::cout << BLUE "Decrementing " << name << "'s grade..." RESET << std::endl;
	if (grade >= 150)
		throw GradeTooLowException();
	++grade;
}

// Methods
void Bureaucrat::signForm(AForm &form) const
{
	try {
		form.beSigned(*this);
	} catch(std::exception &error) {
		std::cerr << RED << name << " could not sign " << form.getName()
		<< " because " << error.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try {
		form.execute(*this);
	} catch(std::exception &error) {
		std::cerr << RED << name << " could not execute " << form.getName()
		<< " because " << error.what() << std::endl;
	}
}

// Exception classes override the what() method
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return BOLD RED "Error: Grade too high." RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return BOLD RED "Error: Grade too low." RESET;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, Bureaucrat const &src)
{
	os << BLUE << src.getName() << ":\tgrade " << src.getGrade() << RESET;
	return os;
}
