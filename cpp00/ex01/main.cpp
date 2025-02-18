/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:42:23 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/18 17:44:48 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main ()
{
	Phonebook phonebook;
	string input;

	while (true)
	{
		cout << "\nEnter command (ADD, SEARCH, EXIT): ";
		getline(cin, input);
		if (input == "EXIT") break;
		else if (input == "ADD") {
			Contact newContact = CreateContact();
			phonebook.AddContact(newContact);
			cout << "Contact added." << endl;
		} else if (input == "SEARCH") {
			phonebook.SearchContact();
		} else
			cout << "Invalid input." << endl;
		if (cin.eof()) break;
	}
	return 0;
}
