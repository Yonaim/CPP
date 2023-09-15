#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *_brain;

  public:
	Cat();
	Cat(const Cat &orig);
	Cat &operator=(const Cat &orig);
	~Cat();

	virtual void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
