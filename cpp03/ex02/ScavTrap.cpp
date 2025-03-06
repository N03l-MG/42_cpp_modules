/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:27:33 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/06 15:06:16 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Orthodox Canonical Form Rewrites (of the ClapTrap defaults)

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap instance " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << "ScavTrap instance " << name << " copied from " << src.name
	<< " and constructed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap instance " << name << " destroyed." << std::endl;
}

// ClapTrap Method Overrides

void ScavTrap::attack(std::string const &target)
{
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << name << " is out of energy or HP."
		<< std::endl;
	}
}

// ScavTrap Class Method

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}
