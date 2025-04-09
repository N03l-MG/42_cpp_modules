/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:14 by kixik             #+#    #+#             */
/*   Updated: 2025/03/06 15:02:59 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// this one is absolutely terrible, no jokes here
	DiamondTrap diamondtrap("Igosefa");
	std::cout << std::endl;

	diamondtrap.whoAmI();
	std::cout << "Hit Points: " << diamondtrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << diamondtrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " <<  diamondtrap.getAttackDamage() << std::endl;
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	diamondtrap.attack("the air... ");
	std::cout << std::endl;

	return 0;
}
