/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:37:56 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 17:13:05 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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
