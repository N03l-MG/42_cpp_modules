/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:19:01 by kixik             #+#    #+#             */
/*   Updated: 2025/02/24 14:38:56 by kixik            ###   ########.fr       */
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
