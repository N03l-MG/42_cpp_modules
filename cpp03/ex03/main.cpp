/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:14 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 17:03:10 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// okay this got annoying, back to boring mains, sorry
	DiamondTrap diamondtrap("Igosefa");
	std::cout << std::endl;

	diamondtrap.whoAmI();
	std::cout << "Hit Points: " << diamondtrap.getHitPoints() << std::endl;
	std::cout << "Energy Points: " << diamondtrap.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " <<  diamondtrap.getAttackDamage() << std::endl;
	diamondtrap.guardGate();
	diamondtrap.highFivesGuys();
	diamondtrap.attack("the air... "); // ScavTrap will attack, because yes.
	std::cout << std::endl;

	return 0;
}
