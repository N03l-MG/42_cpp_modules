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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	// Despite the subject stating that these values must be inherited, this is impossible
	// as there is only one ClapTrap grandparent and so the two childs will have the same 
	// values in memory (essentially one will replace the others when constructed). The
	// only solution to this is to hard-code the value... Not """inherit""" them.
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
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
	std::cout << "DiamondTrap instance " << getDiamondName() << " destroyed." << std::endl;
}

// Unique name getter for DiamondTrap

std::string DiamondTrap::getDiamondName() const { return name;}

// DiamondTrap class method

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello, I am a DiamondTrap named " << getDiamondName() <<
	" and I am the grandchild of the ClapTrap named " << getName() << "!"
	<< std::endl;
}
