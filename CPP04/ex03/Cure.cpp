#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
}

// doesn't make sence
Cure::Cure(const Cure &orig) : AMateria(orig)
{
}

// doesn't make sence
Cure &Cure::operator=(const Cure &orig)
{
	if (this == &orig)
		return (*this);
	_type = orig._type;
	return (*this);
}

Cure::~Cure()
{
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	Cure *clone = new Cure(*this);
	return (clone);
}
