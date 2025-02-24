/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:01 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/24 14:38:56 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int currentSize;
	int oldestIndex;

	std::string TruncateString(const std::string& str);
	bool IsValidIndex(const std::string& input);

public:
	PhoneBook();

	void AddContact(const Contact& contact);
	void SearchContact();
	void DisplayAllContacts();
};

#endif
