#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::attack()
{
	if (weapon == NULL)
	{
		std::cout << name << " has no weapon to attack with." << std::endl;
		return;
	} else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
