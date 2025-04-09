/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:24 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 16:36:27 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

// OCF Defaults

Cat::Cat() : Animal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat instance constructed." << std::endl;
}

Cat::Cat(const Cat &src) : Animal(), brain(new Brain(*(src.brain)))
{
	std::cout << "Cat instance copied and constructed." << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	Animal::operator=(src);
	if (brain)
		delete brain;
	brain = new Brain(*src.brain);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat instance destroyed." << std::endl;
	delete brain;
}

// Class method

void Cat::makeSound() const
{
	std::cout << "mau" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brain;
}
