/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:51 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 14:38:52 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "wrong cat";
	std::cout << "WrongCat instance constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	this->type = src.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat instance destroyed." << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "mau?" << std::endl;
	// never prints bcs its not properly overriding
}
