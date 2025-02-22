#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
