/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:53 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/24 14:39:29 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor initializes the phoneBook with 0 contacts and the oldest index at 0
PhoneBook::PhoneBook() : currentSize(0), oldestIndex(0) {}

std::string PhoneBook::TruncateString(const std::string& str)
{
	// Add a '.' to the end of the string if it's longer than 10 characters
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

bool PhoneBook::IsValidIndex(const std::string& input)
{
	// Check if input is a single digit and within the range of the current size
	if (input.empty() || input.length() > 1)
		return false;
	if (!isdigit(input[0]))
		return false;
	int index = input[0] - '0';
	return (index >= 0 && index < currentSize);
}

void PhoneBook::DisplayAllContacts()
{
	// Print the table of contacts
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|   Index  |First Name| Last Name| Nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	// Loop through all individual contacts and display them with a width of 10
	for (int i = 0; i < currentSize; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << TruncateString(contacts[i].GetFirstName());
		std::cout << "|" << std::setw(10) << TruncateString(contacts[i].GetLastName());
		std::cout << "|" << std::setw(10) << TruncateString(contacts[i].GetNickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::AddContact(const Contact& contact)
{
	// Add a new contact to the phoneBook, overwriting the oldest contact if the phoneBook is full
	contacts[oldestIndex] = contact;
	if (currentSize < MAX_CONTACTS)
		currentSize++;
	// Increment the oldest index and wrap around if it exceeds the maximum number of contacts
	oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
}

void PhoneBook::SearchContact()
{
	std::string input;
	int index;

	// In case no contacts in phoneBook
	if (currentSize == 0) {
		std::cout << "No contacts in phonebook." << std::endl;
		return;
	}
	// Print all contacts and prompt user to enter an index
	DisplayAllContacts();
	std::cout << "Enter index to display Contact Details: ";
	// Get user input and check if it's a valid entry in the phoneBook
	getline(std::cin, input);
	if (!IsValidIndex(input)) {
		std::cout << "No such index or invalid input." << std::endl;
		return;
	}
	// Convert input to an integer and print the contact details
	index = input[0] - '0';
	Contact& contact = contacts[index];
	std::cout << "--- Contact Details: ---" << std::endl;
	std::cout << "First Name: " << contact.GetFirstName() << std::endl;
	std::cout << "Last Name: " << contact.GetLastName() << std::endl;
	std::cout << "Nickname: " << contact.GetNickname() << std::endl;
	std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.GetDarkestSecret() << std::endl;
}
