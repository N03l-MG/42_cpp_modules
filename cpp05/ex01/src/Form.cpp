/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:56 by kixik             #+#    #+#             */
/*   Updated: 2025/04/07 15:56:58 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "TextFormat.hpp"

// Orthodox Canonical Form
Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << BOLD GREEN "Default Form instance constructed." RESET << std::endl;
}

Form::Form(const Form &src) : name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute())
{
	std::cout << BOLD GREEN "Form instance copy-constructed." RESET << std::endl;
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
		this->isSigned = src.getIsSigned();
	// Note: everything else is const and cannot be reassigned (nice, 42)
	return *this;
}

Form::~Form()
{
	std::cout << BOLD MAGENTA "Form instance destroyed." RESET << std::endl;
}

// Parameterized constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << BOLD GREEN "Form instance constructed." RESET << std::endl;
}

// Getters
const std::string &Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

// Methods
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	if (isSigned)
		throw Form::AlreadySignedException();
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << name << std::endl;
}

//	Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return BOLD "grade is too high!" RESET;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return BOLD "grade is too low!" RESET;
}

const char *Form::AlreadySignedException::what() const throw()
{
	return BOLD "form is already signed!" RESET;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, Form const &src)
{
	os << BLUE <<src.getName() << ":\tgrade to sign " << src.getGradeToSign() 
	<< ", grade to execute " << src.getGradeToExecute() << ", signed: "
	<< (src.getIsSigned() ? "yes" : "no") << RESET;
	return os;
}
