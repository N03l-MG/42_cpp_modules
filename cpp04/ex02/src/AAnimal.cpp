/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:17 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 16:37:52 by kixik            ###   ########.fr       */
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
