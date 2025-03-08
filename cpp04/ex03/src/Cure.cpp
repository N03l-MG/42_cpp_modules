#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Materia constructed." << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	std::cout << "Cure Materia copied and constructed." << std::endl;
	*this = src;
}

Cure &Cure::operator=(const Cure &src)
{
	this->type = src.type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure Materia destroyed." << std::endl;
}

AMateria* Cure::clone() const
{
	return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}