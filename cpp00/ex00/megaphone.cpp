/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:14:09 by kixik             #+#    #+#             */
/*   Updated: 2025/02/20 17:10:42 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	// If no arguments, print default message
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	// Loop through all arguments
	for (int i = 1; i < argc; i++)
	{
		// Convert to string class and loop through each character
		std::string str(argv[i]);
		for (int j = 0; j < str.length(); j++)
		{
			// Convert to uppercase and print
			str[j] = toupper(str[j]);
			std::cout << str[j];
		}
	}
	// Flush buffer and print newline
	std::cout << std::endl;
	return 0;
}
