/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:56 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/07 15:56:58 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Orthodox Canonical AForm
AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Default Abstract Form instance constructed." << std::endl;
}

AForm::AForm(const AForm &src) : name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Abstract Form instance copy-constructed." << std::endl;
	*this = src;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
		this->isSigned = src.getIsSigned();
	// Note: everything else is const and cannot be reassigned (nice, 42)
	return *this;
}

AForm::~AForm()
{
	std::cout << "Abstract Form instance destroyed." << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Parameterized Abstract Form instance constructed." << std::endl;
}

// Getters
const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

// Methods
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	if (isSigned) {
		std::cout << bureaucrat.getName() << " cannot sign " << name << " because it is already signed." << std::endl;
		return;
	}
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << name << std::endl;
}

//	Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, AForm const &src)
{
	os << src.getName() << ", form grade to sign " << src.getGradeToSign() << ", form grade to execute " << src.getGradeToExecute() << ", signed: " << (src.getIsSigned() ? "yes" : "no") << std::endl;
	return os;
}
