/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:22:46 by nmonzon           #+#    #+#             */
/*   Updated: 2025/02/24 14:35:58 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Default constructor
Contact::Contact() {}

// Setter and Getter functions
void Contact::SetFirstName(const std::string &name)
{
	firstName = name;
}

void Contact::SetLastName(const std::string &name)
{
	lastName = name;
}

void Contact::SetNickname(const std::string &nick)
{
	nickname = nick;
}

void Contact::SetPhoneNumber(const std::string &number)
{
	phoneNumber = number;
}

void Contact::SetDarkestSecret(const std::string &secret)
{
	darkestSecret = secret;
}

std::string Contact::GetFirstName()
{
	return firstName;
}

std::string Contact::GetLastName()
{
	return lastName;
}

std::string Contact::GetNickname()
{
	return nickname;
}

std::string Contact::GetPhoneNumber()
{
	return phoneNumber;
}

std::string Contact::GetDarkestSecret()
{
	return darkestSecret;
}
