/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:15:41 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/09 14:01:18 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), target("Default")
{
	std::cout << BOLD GREEN "Default Robotomy Request Form instance constructed." RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), target(src.getTarget())
{
	std::cout << BOLD GREEN "Robotomy Request Form instance copy-constructed." RESET << std::endl;
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->target = src.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BOLD MAGENTA "Robotomy Request Form instance destroyed." RESET << std::endl;
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), target(target)
{
	std::cout << BOLD GREEN "Robotomy Request Form instance constructed." RESET << std::endl;
}

// Getters
std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

// Methods
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	static bool willSucceed = false;

	willSucceed = !willSucceed;
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		if (willSucceed)
			std::cout << "Robotomy on " << this->target << " has been successful." << std::endl;
		else
			std::cout << "Robotomy on " << this->target << " has failed." << std::endl;
	}
}
