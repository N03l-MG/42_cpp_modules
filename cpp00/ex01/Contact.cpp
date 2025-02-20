/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:46 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/20 17:53:40 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// Default constructor
Contact::Contact() {}

// Create a new contact by asking the user for input.
// If any field is empty, the user will be prompted again
Contact CreateContact()
{
	Contact contact;
	std::string input;
	bool isValid;
	
	const std::string fields[] = {
		"First Name",
		"Last Name",
		"Nickname",
		"Phone Number",
		"Darkest Secret"
	};

	void (Contact::*setters[])(const std::string&) = {
		&Contact::SetFirstName,
		&Contact::SetLastName,
		&Contact::SetNickname,
		&Contact::SetPhoneNumber,
		&Contact::SetDarkestSecret
	};
	
	do {
		isValid = true;
		for (int i = 0; i < 5; i++) {
			std::cout << "Enter " << fields[i] << ": ";
			getline(std::cin, input);
			if (input.empty()) {
				std::cout << "Error: " << fields[i] << " cannot be empty\n";
				isValid = false;
				break;
			}
			(contact.*setters[i])(input);
		}
	} while (!isValid);

	return contact;
}

// Setter and Getter functions
void Contact::SetFirstName(const std::string &name)
{
	firstName = name;
}

void Contact::SetLastName(const std::string &name)
{
	lastName = name;
}

void Contact::SetNickname(const std::string &nick)
{
	nickname = nick;
}

void Contact::SetPhoneNumber(const std::string &number)
{
	phoneNumber = number;
}

void Contact::SetDarkestSecret(const std::string &secret)
{
	darkestSecret = secret;
}

std::string Contact::GetFirstName() const
{
	return firstName;
}

std::string Contact::GetLastName() const
{
	return lastName;
}

std::string Contact::GetNickname() const
{
	return nickname;
}

std::string Contact::GetPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::GetDarkestSecret() const
{
	return darkestSecret;
}
