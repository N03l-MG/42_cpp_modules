/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:59:36 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/09 13:59:36 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <stdexcept>
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "TextFormat.hpp"

class Intern
{
	private:
		AForm *createShrubberyForm(const std::string &target);
		AForm *createRobotomyRequestForm(const std::string &target);
		AForm *createPresidentialPardonForm(const std::string &target);
	public:
		// Orthodox Canonical Form
		Intern();
		Intern(Intern const &src);
		Intern & operator=(Intern const &src);
		~Intern();

		// Methods
		AForm *makeForm(std::string formName, std::string target);

		// Exceptions
		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
