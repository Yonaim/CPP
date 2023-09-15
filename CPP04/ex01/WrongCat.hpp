#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(const WrongCat &orig);
	WrongCat &operator=(const WrongCat &orig);
	~WrongCat();

	void makeSound(void) const;
};

#endif
