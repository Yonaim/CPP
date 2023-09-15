#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "A Cat object has been created" << std::endl;
}

Cat::Cat(const Cat &orig)
{
	_type = orig._type;
	_brain = new Brain(*orig._brain);
}

Cat &Cat::operator=(const Cat &orig)
{
	_type = orig._type;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "A Cat object has been deleted" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (_brain);
}
