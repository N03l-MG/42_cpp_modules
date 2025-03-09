#include <iostream>

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// NOTE: Uncomment vector code in Character.hpp and .cpp (otherwise forbidden)!

int main()
{
	std::cout << "~~ OFFICIAL TESTS ~~" << std::endl;
	std::cout << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl; // All added newlines for readability!

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	std::cout << std::endl;

	std::cout << "~~ EXTRA TESTS ~~" << std::endl;
	std::cout << std::endl;
	Character dumbledore("dumbledore");
	Character gandalf("gandalf");
	std::cout << std::endl;
	gandalf.equip(src->createMateria("cure"));
	gandalf.equip(src->createMateria("ice"));
	std::cout << std::endl;
	dumbledore = gandalf; // dumbledore's name will now also be gandalf.
	dumbledore.printInventory();
	std::cout << std::endl;
	dumbledore.unequip(0);
	dumbledore.unequip(1);
	std::cout << std::endl;

	std::cout << "~~ REMAINING DELETIONS ~~" << std::endl;
	delete src; // Was still needed after official main as a Materia Source.
	std::cout << std::endl; // Two gandalfs destroyed because dumbledore is a deep copy of gandalf!

	return 0;
}
