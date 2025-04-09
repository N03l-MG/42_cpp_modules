/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:15:38 by kixik             #+#    #+#             */
/*   Updated: 2025/04/07 17:15:38 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5), target("Default")
{
	std::cout << BOLD GREEN "Default Presidential Pardon Form instance constructed." RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), target(src.getTarget())
{
	std::cout << BOLD GREEN "Presidential Pardon Form instance copy-constructed." RESET << std::endl;
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->target = src.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BOLD MAGENTA "Presidential Pardon Form instance destroyed." RESET << std::endl;
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon", 25, 5), target(target)
{
	std::cout << BOLD GREEN "Presidential Pardon Form instance constructed." RESET << std::endl;
}

// Getters
std::string PresidentialPardonForm::getTarget() const
{
	return target;
}

// Methods
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}
