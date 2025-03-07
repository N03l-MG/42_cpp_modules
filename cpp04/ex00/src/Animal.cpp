/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:17 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 14:38:19 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Base Animal instance constructed." << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	this->type = src.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Base Animal instance destroyed." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const {}
