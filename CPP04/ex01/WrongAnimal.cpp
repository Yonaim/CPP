#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "An WrongAnimal object has been created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &orig) : _type(orig._type)
{
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &orig)
{
	_type = orig._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An WrongAnimal object has been deleted" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "* some WEIRD crying sound *" << std::endl;
}

const std::string &WrongAnimal::get_type(void) const
{
	return (_type);
}

void WrongAnimal::set_type(const std::string type)
{
	_type = type;
}