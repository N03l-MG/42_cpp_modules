/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:17 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 16:37:52 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Abstract Animal constructed." << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Abstract Animal copied and constructed." << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	this->type = src.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Abstract Animal destroyed." << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::makeSound() const {}
