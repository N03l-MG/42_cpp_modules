#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : itemCount(0)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = nullptr;
	std::cout << "Materia Source constructed." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src) : itemCount(src.itemCount)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : nullptr;
	std::cout << "Materia Source copied and constructed." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (inventory[i] && (inventory[i] != src.inventory[i])) {
				delete (inventory[i]);
				inventory[i] = nullptr;
			}
			if (src.inventory[i])
				inventory[i] = src.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
		itemCount = src.itemCount;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "Materia Source destroyed." << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m == nullptr)
		return;
	if (itemCount < 4)
		inventory[itemCount++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < itemCount; i++)
	{
		if (inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return nullptr;
}
