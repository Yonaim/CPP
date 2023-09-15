#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	_type = "Cat";
	std::cout << "A Cat object has been created" << std::endl;
}

Cat::Cat(const Cat &orig)
{
	_type = orig._type;
}

Cat &Cat::operator=(const Cat &orig)
{
	_type = orig._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "A Cat object has been deleted" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
