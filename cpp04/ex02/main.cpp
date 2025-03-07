/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:44:14 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 17:12:54 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Now these wont compile because Animal is abstract, thus uninstantiable.

	// const AAnimal j = new Dog();
	// const AAnimal i = new Cat();
	// delete j;
	// delete i;
	
	// Same functionality as before.
	std::cout << "~~ Sound Tests: ~~" << std::endl;
	const Cat garfield;
	const Dog odie;
	std::cout << std::endl;
	garfield.makeSound();
	odie.makeSound();
	std::cout << std::endl;

	std::cout << "~~ Idea Tests: ~~" << std::endl;
	garfield.getBrain()->setIdea(0, "Lasagna");
	odie.getBrain()->setIdea(0, "Bone");
	std::cout << garfield.getType() << ": Garfeild is thinking: " << garfield.getBrain()->getIdea(0) << std::endl;
	std::cout << odie.getType() << ": Odie is thinking: " << odie.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "~~ Brain Copy Tests: ~~" << std::endl;
	garfield.getBrain()->setIdea(99, "Prank odie");
	odie.getBrain()->setIdea(42, "uhhhhh");
	const Dog* d = new Dog(odie);
	const Cat* c = new Cat(garfield);
	std::cout << std::endl;
	std::cout << c->getType() << ": c is thinking: " << c->getBrain()->getIdea(0) << std::endl;
	std::cout << d->getType() << ": d is thinking: " << d->getBrain()->getIdea(0) << std::endl;
	std::cout << c->getType() << ": c is also thinking: " << c->getBrain()->getIdea(99) << std::endl;
	std::cout << d->getType() << ": d is also thinking: " << d->getBrain()->getIdea(42) << std::endl;
	std::cout << std::endl;

	std::cout << "~~ Null Tests: ~~" << std::endl;
	c->getBrain()->setIdea(999, "out of bounds");
	d->getBrain()->setIdea(-10, "too small");
	std::cout << c->getBrain()->getIdea(1) << std::endl;
	std::cout << d->getBrain()->getIdea(99) << std::endl;
	std::cout << std::endl;
	
	// Heap allocations destroyed
	delete c;
	delete d;
	// Remaining Stack allocations automatically destroyed
	return 0;
}
