#include "AbstractAnimal.hpp"
#include <iostream>
#include <string>

AbstractAnimal::AbstractAnimal() : _type("AbstractAnimal")
{
	std::cout << "An AbstractAnimal object has been created" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &orig) : _type(orig._type)
{
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &orig)
{
	_type = orig._type;
	return (*this);
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "An AbstractAnimal object has been deleted" << std::endl;
}

const std::string &AbstractAnimal::get_type(void) const
{
	return (_type);
}

void AbstractAnimal::set_type(const std::string type)
{
	_type = type;
}