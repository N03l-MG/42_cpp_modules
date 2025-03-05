/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:28:36 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 17:09:14 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	std::string name;
	// All other private attributes inherited from ClapTrap, through both child classes
public:
	// OCF constructors and destructor
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap &operator=(const DiamondTrap &src);
	~DiamondTrap();
	// Getter overrides
	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	// ClapTrap Overrides NOT present bcs the subject asks for attack() to come from ScavTrap
	void attack(std::string const &target);
	// Class methods
	void whoAmI();
};

#endif