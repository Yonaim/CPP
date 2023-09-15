#ifndef ABSTRACTCAT_HPP
#define ABSTRACTCAT_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class AbstractCat : public AbstractAnimal
{
  private:
	Brain *_brain;

  public:
	AbstractCat();
	AbstractCat(const AbstractCat &orig);
	AbstractCat &operator=(const AbstractCat &orig);
	~AbstractCat();

	virtual void makeSound(void) const = 0;
	// base class가 abstract class일 때, 순수 가상 함수(pure virtual function)를
	// 구현해주지 않으면 이 유도 클래스 또한 abstract class가 된다.
	Brain *getBrain(void) const;
};

#endif
