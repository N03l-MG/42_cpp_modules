/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:46 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/18 17:58:17 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact() {}

Contact CreateContact()
{
	Contact contact;
	string input;

	cout << "Enter First Name: ";
	getline(cin, input);
	contact.SetFirstName(input);
	cout << "Enter Last Name: ";
	getline(cin, input);
	contact.SetLastName(input);
	cout << "Enter Nickname: ";
	getline(cin, input);
	contact.SetNickname(input);
	cout << "Enter Phone Number: ";
	getline(cin, input);
	contact.SetPhoneNumber(input);
	cout << "Enter Darkest Secret: ";
	getline(cin, input);
	contact.SetDarkestSecret(input);

	return contact;
}

void Contact::SetFirstName(const string &name)
{
	firstName = name;
}

void Contact::SetLastName(const string &name)
{
	lastName = name;
}

void Contact::SetNickname(const string &nick)
{
	nickname = nick;
}

void Contact::SetPhoneNumber(const string &number)
{
	phoneNumber = number;
}

void Contact::SetDarkestSecret(const string &secret)
{
	darkestSecret = secret;
}

string Contact::GetFirstName() const
{
	return firstName;
}

string Contact::GetLastName() const
{
	return lastName;
}

string Contact::GetNickname() const
{
	return nickname;
}

string Contact::GetPhoneNumber() const
{
	return phoneNumber;
}

string Contact::GetDarkestSecret() const
{
	return darkestSecret;
}
