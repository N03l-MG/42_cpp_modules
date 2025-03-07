/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:39:15 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 14:39:27 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// --- Regular main tests --- //
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // Will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	// --- Wrong animal and cat tests --- //
	std::cout << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();
	std::cout << std::endl;

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound(); // Should output the WrongAnimal sound!
	wrong_meta->makeSound(); // Same as above. The WrongCat sound never prints.
	std::cout << std::endl;

	delete wrong_i;
	delete wrong_meta;

	return 0;
}
