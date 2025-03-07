/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:56 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 16:10:09 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
	// Orthodox Canon
		Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		~Cat();
	// Class Methods
		void makeSound() const override;
		Brain *getBrain() const;
};

#endif
