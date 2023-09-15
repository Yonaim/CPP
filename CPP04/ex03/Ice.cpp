#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

// doesn't make sence
Ice::Ice(const Ice &orig) : AMateria(orig)
{
}

// doesn't make sence
Ice &Ice::operator=(const Ice &orig)
{
	if (this == &orig)
		return (*this);
	_type = orig._type;
	return (*this);
}

Ice::~Ice()
{
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}

AMateria *Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return (clone);
}
