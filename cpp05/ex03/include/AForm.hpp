/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:53 by nmonzon           #+#    #+#             */
/*   Updated: 2025/04/07 17:05:48 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"
# include "TextFormat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		// OCF
		AForm();
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		// Parameterized constructor
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);

		// Getters
		virtual const std::string &getName() const;
		virtual bool getIsSigned() const;
		virtual int getGradeToSign() const;
		virtual int getGradeToExecute() const;

		// Methods
		virtual void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

		// Exception class overrides
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
