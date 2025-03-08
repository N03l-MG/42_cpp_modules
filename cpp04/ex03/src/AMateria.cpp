#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "Abstract Materia constructed." << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "Abstract Materia copied and constructed." << std::endl;
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	this->type = src.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "Abstract Materia destroyed." << std::endl;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << type << " Materia used on " << target.getName() << std::endl;
}
