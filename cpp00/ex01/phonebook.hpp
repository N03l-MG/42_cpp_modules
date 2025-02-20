/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:01 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/20 17:29:20 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact 
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();

	void SetFirstName(const std::string &name);
	void SetLastName(const std::string &name);
	void SetNickname(const std::string &nick);
	void SetPhoneNumber(const std::string &number);
	void SetDarkestSecret(const std::string &secret);

	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickname() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;
};

class Phonebook
{
private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int currentSize;
	int oldestIndex;

	std::string TruncateString(const std::string& str);
	void DisplayContact(const Contact& contact, int index);
	bool IsValidIndex(const std::string& input);

public:
	Phonebook();

	void AddContact(const Contact& contact);
	void SearchContact();
	void DisplayAllContacts();
};

Contact CreateContact();

#endif
