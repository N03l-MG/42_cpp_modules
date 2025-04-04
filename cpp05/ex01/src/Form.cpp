/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:56 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/04 15:37:43 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Orthodox Canonical Form
Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Default Form instance constructed." << std::endl;
}

Form::Form(const Form &src) : name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Form instance copy-constructed." << std::endl;
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
	std::cout << "Form instance destroyed." << std::endl;
}

// Parameterized constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Parameterized Form instance constructed." << std::endl;
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
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << name << std::endl;
}

//	Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, Form const &src)
{
	os << src.getName() << ", form grade to sign " << src.getGradeToSign() << ", form grade to execute " << src.getGradeToExecute() << ", signed: " << (src.getIsSigned() ? "yes" : "no") << std::endl;
	return os;
}
