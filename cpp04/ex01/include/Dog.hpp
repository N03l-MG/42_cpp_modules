/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kixik   <github.com/kixikCodes>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:38:00 by kixik             #+#    #+#             */
/*   Updated: 2025/03/07 16:10:12 by kixik            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
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
