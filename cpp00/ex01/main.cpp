/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:42:23 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/24 14:42:57 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact CreateContact();

int main ()
{
	PhoneBook phonebook;
	std::string input;

	// main program loop
	while (true)
	{
		std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
		getline(std::cin, input);
		if (input == "EXIT") break;
		else if (input == "ADD") {
			Contact newContact = CreateContact();
			phonebook.AddContact(newContact);
			std::cout << "Contact added." << std::endl;
		} else if (input == "SEARCH") {
			phonebook.SearchContact();
		}
		if (std::cin.eof()) break;
	}
	return 0;
}

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
			if (std::cin.eof()) break;
			else if (input.empty()) {
				std::cout << "Error: " << fields[i] << " cannot be empty\n";
				isValid = false;
				break;
			}
			(contact.*setters[i])(input);
		}
	} while (!isValid);

	return contact;
}
