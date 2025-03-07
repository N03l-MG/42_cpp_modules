/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:24 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 17:04:07 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

// OCF Defaults

Cat::Cat() : AAnimal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat instance constructed." << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(), brain(new Brain(*(src.brain)))
{
	std::cout << "Cat instance copied and constructed." << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	AAnimal::operator=(src);
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
