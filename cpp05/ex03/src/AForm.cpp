/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:56 by kixik             #+#    #+#             */
/*   Updated: 2025/04/07 15:56:58 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Orthodox Canonical AForm
AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << BOLD GREEN "Default Abstract Form constructed." RESET << std::endl;
}

AForm::AForm(const AForm &src) : name(src.getName()), isSigned(src.getIsSigned()), gradeToSign(src.getGradeToSign()), gradeToExecute(src.getGradeToExecute())
{
	std::cout << BOLD GREEN "Abstract Form copy-constructed." RESET << std::endl;
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
	std::cout << BOLD MAGENTA "Abstract Form destroyed." RESET << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << BOLD GREEN "Abstract Form constructed." RESET << std::endl;
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
	if (isSigned)
		throw AForm::AlreadySignedException();
	isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << name << std::endl;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned)
		throw AForm::NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	std::cout << executor.getName() << " executed " << name << std::endl;
}

//	Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return BOLD "grade is too high!" RESET;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return BOLD "grade is too low!" RESET;
}

const char *AForm::NotSignedException::what() const throw()
{
	return BOLD "form is not signed!" RESET;
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return BOLD "form is already signed!" RESET;
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, AForm const &src)
{
	os << BLUE <<src.getName() << ":\tgrade to sign " << src.getGradeToSign() 
	<< ", grade to execute " << src.getGradeToExecute() << ", signed: "
	<< (src.getIsSigned() ? "yes" : "no") << RESET;
	return os;
}
