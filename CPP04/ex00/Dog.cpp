#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	_type = "Dog";
	std::cout << "A Dog object has been created" << std::endl;
}

Dog::Dog(const Dog &orig)
{
	_type = orig._type;
}

Dog &Dog::operator=(const Dog &orig)
{
	_type = orig._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "A Dog object has been deleted" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "bark" << std::endl;
}
