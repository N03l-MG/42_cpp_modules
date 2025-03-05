/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:33 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 17:17:55 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Orthodox Canonical Form

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	setName(name);
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap instance " << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap::ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "DiamondTrap instance " << getName() << " copied from " << src.getName()
	<< " and constructed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap instance " << getName() << " destroyed." << std::endl;
}

// Getter Overrides (diamond inheritance problem solution)

std::string ClapTrap::getName() const { return name; }

unsigned int ClapTrap::getHitPoints() { return FragTrap::getHitPoints(); }

unsigned int ClapTrap::getEnergyPoints() { return ScavTrap::getEnergyPoints(); }

unsigned int ClapTrap::getAttackDamage() { return FragTrap::getAttackDamage(); }

// ScavTrap Method Inheritance (only attack)

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

// DiamondTrap class method

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello, I am a DiamondTrap named " << getName() <<
	" and I am the grandchild of the ClapTrap named " << ClapTrap::getName() << "!"
	<< std::endl;
}
