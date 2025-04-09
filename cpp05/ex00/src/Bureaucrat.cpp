/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:50:51 by kixik             #+#    #+#             */
/*   Updated: 2025/04/04 14:53:59 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << "Default Bureaucrat instance constructed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), grade(src.getGrade())
{
	std::cout << "Bureaucrat instance copy-constructed." << std::endl;
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
	std::cout << "Bureaucrat instance destroyed." << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "Bureaucrat " << name <<" constructed." << std::endl;
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
	if (grade <= 1)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	++grade;
}

// Exception classes override the what() method
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, Bureaucrat const &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return os;
}
