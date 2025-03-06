#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Base Animal instance constructed." << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	this->type = src.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Base Animal instance destroyed." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const {}
