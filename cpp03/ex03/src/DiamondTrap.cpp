/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:33 by kixik             #+#    #+#             */
/*   Updated: 2025/03/06 14:57:38 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Orthodox Canonical Form

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	ScavTrap temp("");
	this->hitPoints = FragTrap::hitPoints;
	this->attackDamage = FragTrap::attackDamage;
	this->energyPoints = temp.getEnergyPoints();
	std::cout << "DiamondTrap instance " << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "DiamondTrap instance " << name << " copied from " << src.name
	<< " and constructed." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap instance " << name << " destroyed." << std::endl;
}

// Getter and Setter overrides

std::string DiamondTrap::getName() const { return this->name; }

unsigned int DiamondTrap::getHitPoints() const { return this->hitPoints; }

unsigned int DiamondTrap::getEnergyPoints() const { return this->energyPoints; }

unsigned int DiamondTrap::getAttackDamage() const { return this->attackDamage; }

void DiamondTrap::setName(std::string name) { this->name = name; }

void DiamondTrap::setHitPoints(unsigned int hitPoints) { this->hitPoints = hitPoints; }

void DiamondTrap::setEnergyPoints(unsigned int energyPoints) { this->energyPoints = energyPoints; }

void DiamondTrap::setAttackDamage(unsigned int attackDamage) { this->attackDamage = attackDamage; }

// DiamondTrap class method

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hello, I am a DiamondTrap named " << name <<
	" and I am the grandchild of the ClapTrap named " << ClapTrap::name << "!"
	<< std::endl;
}
