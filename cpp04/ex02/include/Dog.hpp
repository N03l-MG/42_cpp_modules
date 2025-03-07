/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:00 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 17:13:08 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
	public:
	// Orthodox Canon
		Dog();
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		~Dog();
	// Class Methods
		void makeSound() const override;
		Brain *getBrain() const;
};

#endif
