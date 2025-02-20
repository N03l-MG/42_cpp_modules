/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:53 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/20 17:51:21 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// Constructor initializes the phonebook with 0 contacts and the oldest index at 0
Phonebook::Phonebook() : currentSize(0), oldestIndex(0) {}

std::string Phonebook::TruncateString(const std::string& str)
{
	// Add a '.' to the end of the string if it's longer than 10 characters
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

bool Phonebook::IsValidIndex(const std::string& input)
{
	// Check if input is a single digit and within the range of the current size
	if (input.empty() || input.length() > 1)
		return false;
	if (!isdigit(input[0]))
		return false;
	int index = input[0] - '0';
	return (index >= 0 && index < currentSize);
}

void Phonebook::DisplayContact(const Contact& contact, int index)
{
	// Print contact details as a row in the table, each column is 10 characters wide
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << TruncateString(contact.GetFirstName());
	std::cout << "|" << std::setw(10) << TruncateString(contact.GetLastName());
	std::cout << "|" << std::setw(10) << TruncateString(contact.GetNickname());
	std::cout << "|" << std::endl;
}

void Phonebook::DisplayAllContacts()
{
	// Print the table of contacts
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < currentSize; i++)
		DisplayContact(contacts[i], i);
	std::cout << "|-------------------------------------------|" << std::endl;
}

void Phonebook::AddContact(const Contact& contact)
{
	// Add a new contact to the phonebook, overwriting the oldest contact if the phonebook is full
	contacts[oldestIndex] = contact;
	if (currentSize < MAX_CONTACTS)
		currentSize++;
	// Increment the oldest index and wrap around if it exceeds the maximum number of contacts
	oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
}

void Phonebook::SearchContact()
{
	std::string input;
	int index;

	// In case no contacts in phonebook
	if (currentSize == 0) {
		std::cout << "No contacts in phonebook." << std::endl;
		return;
	}
	// Print all contacts and prompt user to enter an index
	DisplayAllContacts();
	std::cout << "Enter index to display Contact Details: ";
	// Get user input and check if it's a valid entry in the phonebook
	getline(std::cin, input);
	if (!IsValidIndex(input)) {
		std::cout << "No such index or invalid input." << std::endl;
		return;
	}
	// Convert input to an integer and print the contact details
	index = input[0] - '0';
	const Contact& contact = contacts[index];
	std::cout << "--- Contact Details: ---" << std::endl;
	std::cout << "First Name: " << contact.GetFirstName() << std::endl;
	std::cout << "Last Name: " << contact.GetLastName() << std::endl;
	std::cout << "Nickname: " << contact.GetNickname() << std::endl;
	std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << std::endl;
}
