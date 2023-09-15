#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "A WrongCat object has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &orig)
{
	_type = orig._type;
}

WrongCat &WrongCat::operator=(const WrongCat &orig)
{
	_type = orig._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat object has been deleted" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
