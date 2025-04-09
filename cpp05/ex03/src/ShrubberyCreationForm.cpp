/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:15:44 by kixik             #+#    #+#             */
/*   Updated: 2025/04/07 17:15:44 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), target("Default")
{
	std::cout << BOLD GREEN "Default Shrubbery Creation Form instance constructed." RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target(src.getTarget())
{
	std::cout << BOLD GREEN "Shrubbery Creation Form instance copy-constructed." RESET << std::endl;
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->target = src.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD MAGENTA "Shrubbery Creation Form instance destroyed." RESET << std::endl;
}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), target(target)
{
	std::cout << BOLD GREEN "Shrubbery Creation Form instance constructed." RESET << std::endl;
}

// Getters
std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}

// Methods
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else {
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::ofstream file(target + "_shrubbery");
		if (!file.is_open())
			throw OpenFileExeption();
		else {
			file << "              * *           " << std::endl;
			file << "           *    *  *        " << std::endl;
			file << "      *  *    *     *  *    " << std::endl;
			file << "     *     *    *  *    *   " << std::endl;
			file << " * *   *    *    *    *   * " << std::endl;
			file << " *     *  *    * * .#  *   *" << std::endl;
			file << " *   *     * #.  .# *   *   " << std::endl;
			file << "  *     :#.  #: #: * *    * " << std::endl;
			file << " *   * * :#. ##:       *    " << std::endl;
			file << "   *       :###             " << std::endl;
			file << "             :##  ,         " << std::endl;
			file << "              ##./          " << std::endl;
			file << "              .##:          " << std::endl;
			file << "              :###          " << std::endl;
			file << "              ;###          " << std::endl;
			file << "            ,####.          " << std::endl;
			file << "<><><><><>.######.<><><><><>" << std::endl;
			file.close();
			std::cout << "Shrubbery created in file " << target + "_shrubbery." << std::endl;
		}
	}
}

//	Exception class what() method override
const char	*ShrubberyCreationForm::OpenFileExeption::what() const throw()
{
	return RED "Failed to open file!" RESET;
}
