/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:51 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 17:08:53 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
	// Orthodox Defaults
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		virtual ~AAnimal();
	// Abstract Class Methods
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
