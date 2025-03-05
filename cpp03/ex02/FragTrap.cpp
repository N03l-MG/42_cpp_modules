/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:42:45 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 14:53:34 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Orthodox Canonical Form Rewrites (of the ClapTrap defaults)

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "FragTrap instance " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap::ClapTrap(src)
{
	*this = src;
	std::cout << "FragTrap instance " << getName() << " copied from " << src.getName()
	<< " and constructed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap instance " << getName() << " destroyed." << std::endl;
}

// ClapTrap Method Overrides

void FragTrap::attack(std::string const &target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << getName() << " attacks " << target
		<< ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " is out of energy or HP."
		<< std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount > 0) {
		if (getHitPoints() > amount) {
			setHitPoints(getHitPoints() - amount);
			std::cout << "FragTrap " << getName() << " takes " << amount
					  << " points of damage!" << std::endl;
		} else {
			setHitPoints(0);
			std::cout << "FragTrap " << getName() << " takes " << amount
					  << " points of damage... It is now broken." << std::endl;
		}
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		setHitPoints(getHitPoints() + amount);
		std::cout << "FragTrap " << getName() << " repairs itself for " << amount
				  << " HP." << std::endl;
	} else {
		std::cout << "FragTrap " << getName() << " has insufficient energy or is broken."
		<< std::endl;
	}
}

// FragTrap Class Method

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " requests a high-five!" << std::endl;
}
