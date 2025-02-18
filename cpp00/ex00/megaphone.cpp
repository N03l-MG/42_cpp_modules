/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:14:09 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/18 17:21:56 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

string capitalize(string str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}

void main(int argc, char **argv)
{
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return;
	}
	for (int i = 1; i < argc; i++)
	{
		string str(argv[i]);
		cout << capitalize(str);
	}
	cout << endl;
	return;
}
