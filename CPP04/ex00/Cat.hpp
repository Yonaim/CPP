#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  public:
	Cat();
	Cat(const Cat &orig);
	Cat &operator=(const Cat &orig);
	~Cat();

	virtual void makeSound(void) const;
};

#endif
