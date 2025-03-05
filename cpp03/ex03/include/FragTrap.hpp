/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:42:48 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/05 16:01:22 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	// All private attributes inherited from ClapTrap
public:
	// OCF constructor and destructor overrides
	FragTrap(std::string name);
	FragTrap(const FragTrap &src);
	FragTrap &operator=(const FragTrap &src);
	~FragTrap();
	// ClapTrap Overrides
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	// Class methods
	void highFivesGuys();
};

#endif