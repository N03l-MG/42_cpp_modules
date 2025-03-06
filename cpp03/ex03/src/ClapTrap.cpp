/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:53:47 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/06 14:00:43 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Orthodox Canonical Form Defaults

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap instance " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout << "ClapTrap instance " << name << " copied from " << src.name
	<< " and constructed." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	// std::cout << "Class copy assignment overload called." << std::endl;
	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap instance " << name << " destroyed." << std::endl;
}

// Getters and Setters (for displaying stats in main)

std::string ClapTrap::getName() const { return name; }

unsigned int ClapTrap::getHitPoints() const { return hitPoints; }

unsigned int ClapTrap::getEnergyPoints() const { return energyPoints; }

unsigned int ClapTrap::getAttackDamage() const { return attackDamage; }

void ClapTrap::setName(std::string name) { this->name = name; }

void ClapTrap::setHitPoints(unsigned int hitPoints) { this->hitPoints = hitPoints; }

void ClapTrap::setEnergyPoints(unsigned int energyPoints) { this->energyPoints = energyPoints; }

void ClapTrap::setAttackDamage(unsigned int attackDamage) { this->attackDamage = attackDamage; }


// Class Methods

void ClapTrap::attack(std::string const &target)
{
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " is out of energy or HP."
		<< std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > 0) {
		if (hitPoints > amount) {
			hitPoints -= amount;
			std::cout << "ClapTrap " << name << " takes " << amount
					  << " points of damage!" << std::endl;
		} else {
			hitPoints = 0;
			std::cout << "ClapTrap " << name << " takes " << amount
					  << " points of damage... It is now broken." << std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount
				  << " HP." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has insufficient energy or is broken."
		<< std::endl;
	}
}
