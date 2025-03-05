/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:27:33 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 14:27:35 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Orthodox Canonical Form Rewrites (of the ClapTrap defaults)

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap instance " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap::ClapTrap(src)
{
	*this = src;
	std::cout << "ScavTrap instance " << getName() << " copied from " << src.getName()
	<< " and constructed." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap instance " << getName() << " destroyed." << std::endl;
}

// ClapTrap Method Overrides

void ScavTrap::attack(std::string const &target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " is out of energy or HP."
		<< std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > 0) {
		if (getHitPoints() > amount) {
			setHitPoints(getHitPoints() - amount);
			std::cout << "ScavTrap " << getName() << " takes " << amount
					  << " points of damage!" << std::endl;
		} else {
			setHitPoints(0);
			std::cout << "ScavTrap " << getName() << " takes " << amount
					  << " points of damage... It is now broken." << std::endl;
		}
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		setHitPoints(getHitPoints() + amount);
		std::cout << "ScavTrap " << getName() << " repairs itself for " << amount
				  << " HP." << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " has insufficient energy or is broken."
		<< std::endl;
	}
}

// ScavTrap Class Method

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode." << std::endl;
}
