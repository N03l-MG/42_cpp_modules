/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:54:31 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 16:56:49 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

// OCF Defaults

Brain::Brain()
{
	// Idea strings get automaically initialized as empty by C++.
	std::cout << "Brain instance constructed." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain instance copied and constructed." << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain instance destroyed." << std::endl;
}

// Getter/Setter

std::string Brain::getIdea(size_t index) const
{
	if (!(ideas[index].empty()))
		return (this->ideas[index]);
	return "Has no thoughts here...";
}

void Brain::setIdea(size_t index, std::string ideaString)
{
	if (index >= 0 && index < 100) {
		this->ideas[index].assign(ideaString);
		return;
	}
	std::cout << "No such index in Brain." << std::endl;
}
