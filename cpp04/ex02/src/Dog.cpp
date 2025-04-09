/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:29 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 17:04:30 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

// OCF Defaults

Dog::Dog() : AAnimal(), brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog instance constructed." << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(), brain(new Brain(*(src.brain)))
{
	std::cout << "Dog instance copied and constructed." << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	AAnimal::operator=(src);
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
