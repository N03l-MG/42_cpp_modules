/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:29 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 14:38:29 by kixik            ###   ########.fr       */
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
