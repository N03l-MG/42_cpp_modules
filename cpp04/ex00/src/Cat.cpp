#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "cat";
	std::cout << "Cat instance constructed." << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	this->type = src.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat instance destroyed." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "mau" << std::endl;
}
