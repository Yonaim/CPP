#include "AbstractCat.hpp"
#include <iostream>

AbstractCat::AbstractCat()
{
	_type = "AbstractCat";
	_brain = new Brain();
	std::cout << "A AbstractCat object has been created" << std::endl;
}

AbstractCat::AbstractCat(const AbstractCat &orig)
{
	_type = orig._type;
	_brain = new Brain(*orig._brain);
}

AbstractCat &AbstractCat::operator=(const AbstractCat &orig)
{
	_type = orig._type;
	return (*this);
}

AbstractCat::~AbstractCat()
{
	delete _brain;
	std::cout << "A AbstractCat object has been deleted" << std::endl;
}

Brain *AbstractCat::getBrain(void) const
{
	return (_brain);
}
