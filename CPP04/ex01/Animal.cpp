#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() : _type("Animal")
{
	std::cout << "An Animal object has been created" << std::endl;
}

Animal::Animal(const Animal &orig) : _type(orig._type)
{
}

Animal &Animal::operator=(const Animal &orig)
{
	_type = orig._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "An Animal object has been deleted" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "* some crying sound *" << std::endl;
}

const std::string &Animal::get_type(void) const
{
	return (_type);
}

void Animal::set_type(const std::string type)
{
	_type = type;
}