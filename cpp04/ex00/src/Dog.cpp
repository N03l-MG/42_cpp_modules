/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:29 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 14:38:29 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "dog";
	std::cout << "Dog instance constructed." << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	this->type = src.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog instance destroyed." << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "wau" << std::endl;
}
