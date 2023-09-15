#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria '" << _type << "' created" << std::endl;
}

AMateria::AMateria(const AMateria &orig) : _type(orig._type)
{
}

AMateria &AMateria::operator=(const AMateria &orig)
{
	_type = orig._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria '" << _type << "' deleted" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* some kind of Materia was used and affect "
			  << target.getName() << " *" << std::endl;
}
