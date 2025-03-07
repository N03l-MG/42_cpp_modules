/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:29 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 16:36:25 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

// OCF Defaults

Dog::Dog() : Animal(), brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog instance constructed." << std::endl;
}

Dog::Dog(const Dog &src) : Animal(), brain(new Brain(*(src.brain)))
{
	std::cout << "Dog instance copied and constructed." << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	Animal::operator=(src);
	if (brain)
		delete brain;
	brain = new Brain(*src.brain);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog instance destroyed." << std::endl;
	delete brain;
}

// Class method

void Dog::makeSound() const
{
	std::cout << "wau" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}
