/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmonzon <nmonzon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:44:14 by nmonzon           #+#    #+#             */
/*   Updated: 2025/03/07 16:53:02 by nmonzon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "~~ Subject's Main: (construction / destruction tests) ~~" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl; // New lines added by me for readability.
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "~~ Subject's Main: (Array Test) ~~" << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];
	// Fill half with Dogs and half with Cats
	for (int i = 0; i < arraySize / 2; ++i)
		animals[i] = new Dog();
	for (int i = arraySize / 2; i < arraySize; ++i)
		animals[i] = new Cat();
	// Delete all animals
	for (int i = 0; i < arraySize; ++i)
		delete animals[i];
	std::cout << std::endl;
	
	// Everything from this point is my own tests.
	std::cout << std::endl;
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
