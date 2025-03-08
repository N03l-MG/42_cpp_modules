#include <iostream>
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

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

	Character dumbledore("dumbledore");
	Character gandalf("gandalf");
	gandalf.equip(src->createMateria("cure"));
	gandalf.equip(src->createMateria("ice"));
	dumbledore = gandalf;
	dumbledore.printInventory();
	dumbledore.unequip(0); // TODO: figure out a way to free this later...
	dumbledore.unequip(1);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;

	return 0;
}
