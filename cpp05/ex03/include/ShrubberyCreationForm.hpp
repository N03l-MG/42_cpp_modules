/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:43:55 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/09 13:59:48 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		// Orthodox Canonical Form
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();

		// Parameterized constructor
		ShrubberyCreationForm(const std::string &target);

		// Getters
		std::string getTarget() const;

		// Methods
		void execute(const Bureaucrat &executor) const;

		// Exception classes
		class OpenFileExeption : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
