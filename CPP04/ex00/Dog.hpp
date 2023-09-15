#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
  public:
	Dog();
	Dog(const Dog &orig);
	Dog &operator=(const Dog &orig);
	~Dog();

	virtual void makeSound(void) const;
};

#endif
