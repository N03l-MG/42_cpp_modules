/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:53 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/18 18:06:58 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : currentSize(0), oldestIndex(0) {}

string Phonebook::TruncateString(const string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Phonebook::AddContact(const Contact& contact)
{
	contacts[oldestIndex] = contact;
	if (currentSize < MAX_CONTACTS)
		currentSize++;
	oldestIndex = (oldestIndex + 1) % MAX_CONTACTS;
}

void Phonebook::DisplayContact(const Contact& contact, int index)
{
	cout << "|" << setw(10) << index;
	cout << "|" << setw(10) << TruncateString(contact.GetFirstName());
	cout << "|" << setw(10) << TruncateString(contact.GetLastName());
	cout << "|" << setw(10) << TruncateString(contact.GetNickname());
	cout << "|" << endl;
}

bool Phonebook::IsValidIndex(const string& input)
{
	if (input.empty() || input.length() > 1)
		return false;
	if (!isdigit(input[0]))
		return false;
	int index = input[0] - '0';
	return (index >= 0 && index < currentSize);
}

void Phonebook::DisplayAllContacts()
{
	cout << "|----------|----------|----------|----------|" << endl;
	cout << "|   Index  |First Name| Last Name| Nickname |" << endl;
	cout << "|----------|----------|----------|----------|" << endl;
	for (int i = 0; i < currentSize; i++)
		DisplayContact(contacts[i], i);
	cout << "|-------------------------------------------|" << endl;
}

void Phonebook::SearchContact()
{
	string input;

	if (currentSize == 0) {
		cout << "Phonebook is empty." << endl;
		return;
	}
	DisplayAllContacts();
	cout << "Enter index to display Contact Details: ";
	getline(cin, input);
	if (!IsValidIndex(input)) {
		cout << "Invalid index." << endl;
		return;
	}
	int index = input[0] - '0';
	const Contact& contact = contacts[index];
	cout << "\nContact Details:" << endl;
	cout << "First Name: " << contact.GetFirstName() << endl;
	cout << "Last Name: " << contact.GetLastName() << endl;
	cout << "Nickname: " << contact.GetNickname() << endl;
	cout << "Phone Number: " << contact.GetPhoneNumber() << endl;
	cout << "Darkest Secret: " << contact.GetDarkestSecret() << endl;
}
