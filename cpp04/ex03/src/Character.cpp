#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const &name) : name(name)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = nullptr;
	std::cout << "Character: " << name << " constructed." << std::endl;
}

Character::Character(const Character &src) : name(src.name)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : nullptr;
	std::cout << "Character: " << name << " copied and constructed." << std::endl;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->name = src.name;
		for (size_t i = 0; i < 4; i++)
		{
			if (inventory[i] && (inventory[i] != src.inventory[i])) {
				delete inventory[i];
				inventory[i] = nullptr;
			}
			if (src.inventory[i])
				inventory[i] = src.inventory[i]->clone();
			else
				inventory[i] = nullptr;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	// for (AMateria* materia : floor)
	// 	delete materia;
	std::cout << "Character: " << name << " destroyed." << std::endl;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!inventory[i]) {
			inventory[i] = m;
			std::cout << name << " equiped " << m->getType() << " materia." << std::endl;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if ((idx >= 0 && idx < 4) && inventory[idx]) {
		//floor.push_back(inventory[idx]);
		std::cout << name << " dropped " << inventory[idx]->getType() << " materia on the floor." << std::endl;
		this->inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if ((idx >= 0 && idx < 4) && inventory[idx])
		this->inventory[idx]->use(target);
}

void Character::printInventory()
{
	std::cout << name << "'s Inventory:" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == nullptr)
			std::cout << "\t" << i << ": Empty" << std::endl;
		else
			std::cout << "\t" << i << ": " << inventory[i]->getType() << std::endl;
	}
}
