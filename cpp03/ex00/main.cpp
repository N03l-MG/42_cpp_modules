/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:56:14 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/06 15:15:51 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap1("igor");
	ClapTrap claptrap2("josefa");
	claptrap1.setAttackDamage(5); // set atack damages to not 0...
	claptrap2.setAttackDamage(8);
	claptrap1.setEnergyPoints(1); // igor weak af fr
	std::cout << std::endl;

	// Epic cinematic fight between two ClapTraps:

	claptrap1.attack("josefa"); // igor attacks josefa for no reason
	claptrap2.takeDamage(5); // she takes damage

	std::cout << "Igor's HP and Energy Points: "<< claptrap1.getHitPoints()
			  << ", " << claptrap1.getEnergyPoints() << std::endl;
	std::cout << "Josefa's HP and Energy Points: "<< claptrap2.getHitPoints()
			  << ", " << claptrap2.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	claptrap2.attack("igor"); // josefa is like nahh and hits igor back
	claptrap1.takeDamage(8); // she's stronger
	claptrap2.beRepaired(4); // josefa also repairs herself

	std::cout << "Igor's HP and Energy Points: "<< claptrap1.getHitPoints()
			  << ", " << claptrap1.getEnergyPoints() << std::endl;
	std::cout << "Josefa's HP and Energy Points: "<< claptrap2.getHitPoints()
			  << ", " << claptrap2.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	claptrap1.beRepaired(8); // fails bcs energy is already 0 L bozo
	claptrap2.attack("igor"); // no mercy, all my homies hate igor
	claptrap1.takeDamage(8); // he dies

	std::cout << "Igor's HP and Energy Points: "<< claptrap1.getHitPoints()
			  << ", " << claptrap1.getEnergyPoints() << std::endl;
	std::cout << "Josefa's HP and Energy Points: "<< claptrap2.getHitPoints()
			  << ", " << claptrap2.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	return 0; // lol
}
