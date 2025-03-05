/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:14 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 15:23:37 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void displayBothStats(ScavTrap &scavtrap, FragTrap &fragtrap)
{
	std::cout << "Igor2.0's HP and Energy Points: "<< scavtrap.getHitPoints()
			  << ", " << scavtrap.getEnergyPoints() << std::endl;
	std::cout << "Josefa2.0's HP and Energy Points: "<< fragtrap.getHitPoints()
			  << ", " << fragtrap.getEnergyPoints() << std::endl;
	std::cout << std::endl;
}

int main()
{
	ScavTrap scavtrap("igor2.0");
	FragTrap fragtrap("josefa2.0"); // wow im so surprised
	std::cout << std::endl;

	// Its a trillogy now

	scavtrap.guardGate(); // asserts dominance (this does nothing btw)
	fragtrap.attack("igor2.0");
	scavtrap.takeDamage(30);
	displayBothStats(scavtrap, fragtrap);

	scavtrap.attack("josefa2.0");
	fragtrap.takeDamage(20);
	displayBothStats(scavtrap, fragtrap);

	scavtrap.beRepaired(10); // preventing an incoming attack
	fragtrap.attack("igor2.0");
	scavtrap.takeDamage(30); // health is still slightly higher thanks to repair
	displayBothStats(scavtrap, fragtrap);

	scavtrap.attack("josefa2.0");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(10); // goated strat
	displayBothStats(scavtrap, fragtrap);

	fragtrap.attack("igor2.0");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(10); // clinging on to dear life
	displayBothStats(scavtrap, fragtrap);

	fragtrap.highFivesGuys(); // with her victory assured, she offers peace :D
	std::cout << std::endl;

	return 0; // the good ending
}
