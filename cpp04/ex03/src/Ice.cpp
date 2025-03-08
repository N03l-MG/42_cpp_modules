#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Materia constructed." << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	std::cout << "Ice Materia copied and constructed." << std::endl;
	*this = src;
}

Ice &Ice::operator=(const Ice &src)
{
	this->type = src.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice Materia destroyed." << std::endl;
}

AMateria* Ice::clone() const
{
	return(new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
