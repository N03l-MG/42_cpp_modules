/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:01 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/18 17:58:56 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Contact 
{
private:
	string firstName;
	string lastName;
	string nickname;
	string phoneNumber;
	string darkestSecret;

public:
	Contact();
	Contact CreateContact();

	void SetFirstName(const string &name);
	void SetLastName(const string &name);
	void SetNickname(const string &nick);
	void SetPhoneNumber(const string &number);
	void SetDarkestSecret(const string &secret);

	string GetFirstName() const;
	string GetLastName() const;
	string GetNickname() const;
	string GetPhoneNumber() const;
	string GetDarkestSecret() const;
};

class Phonebook
{
private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int currentSize;
	int oldestIndex;

	string TruncateString(const string& str);
	void DisplayContact(const Contact& contact, int index);
	bool IsValidIndex(const string& input);

public:
	Phonebook();

	void AddContact(const Contact& contact);
	void SearchContact();
	void DisplayAllContacts();
};

#endif
