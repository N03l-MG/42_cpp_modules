/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:17 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 16:37:52 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Base Animal instance constructed." << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Base Animal instance copied and constructed." << std::endl;
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
