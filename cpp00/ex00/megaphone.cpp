/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:14:09 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/17 17:28:19 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string capitalize(std::string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return str;
}

void main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return;
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		std::cout << capitalize(str);
	}
	std::cout << std::endl;
	return;
}
