/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:14 by kixik             #+#    #+#             */
/*   Updated: 2025/03/05 14:27:30 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavtrap("igor2.0"); // the comeback..
	ClapTrap claptrap("josefa");
	claptrap.setAttackDamage(8);
	std::cout << std::endl;

	// Epic fight part 2 - Electric Boogaloo:

	claptrap.attack("igor2.0"); // this time she strikes first
	scavtrap.takeDamage(8);

	std::cout << "Igor2.0's HP and Energy Points: "<< scavtrap.getHitPoints()
			  << ", " << scavtrap.getEnergyPoints() << std::endl;
	std::cout << "Josefa's HP and Energy Points: "<< claptrap.getHitPoints()
			  << ", " << claptrap.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	claptrap.attack("igor2.0"); // and again
	scavtrap.takeDamage(8);
	scavtrap.beRepaired(16); // he aint even budging

	std::cout << "Igor2.0's HP and Energy Points: "<< scavtrap.getHitPoints()
			  << ", " << scavtrap.getEnergyPoints() << std::endl;
	std::cout << "Josefa's HP and Energy Points: "<< claptrap.getHitPoints()
			  << ", " << claptrap.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	scavtrap.attack("josefa");
	claptrap.takeDamage(20); // ZAAAAAAAAMNN
	scavtrap.guardGate(); // and the flex...
	std::cout << std::endl;

	return 0; // absolute cinema
}
