/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:42:45 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/06 15:07:19 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Orthodox Canonical Form Rewrites (of the ClapTrap defaults)

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap instance " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "FragTrap instance " << name << " copied from " << src.name
	<< " and constructed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap instance " << name << " destroyed." << std::endl;
}

// ClapTrap Method Overrides

void FragTrap::attack(std::string const &target)
{
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "FragTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << name << " is out of energy or HP."
		<< std::endl;
	}
}

// FragTrap Class Method

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a high-five!" << std::endl;
}
