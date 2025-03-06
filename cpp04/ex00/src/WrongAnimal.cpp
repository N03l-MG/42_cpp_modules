#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Base WrongAnimal instance constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	this->type = src.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Base WrongAnimal instance destroyed." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "wrong sound" << std::endl;
}
