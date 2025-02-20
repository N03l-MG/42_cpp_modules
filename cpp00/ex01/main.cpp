/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:42:23 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/20 17:30:41 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main ()
{
	Phonebook phonebook;
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
