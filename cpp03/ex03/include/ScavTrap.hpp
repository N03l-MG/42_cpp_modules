/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:27:39 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 16:01:17 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	// All private attributes inherited from ClapTrap
public:
	// OCF constructor and destructor overrides
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &src);
	~ScavTrap();
	// ClapTrap Overrides
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	// Class methods
	void guardGate();
};

#endif
