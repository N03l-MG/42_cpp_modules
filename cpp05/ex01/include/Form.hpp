/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:57:53 by kixik             #+#    #+#             */
/*   Updated: 2025/04/07 15:43:20 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		// OCF
		Form();
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		// Parameterized constructor
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		// Getters
		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		// Methods
		void beSigned(const Bureaucrat &bureaucrat);

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

		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
