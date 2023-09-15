#ifndef CAT_HPP
#define CAT_HPP

#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat : public AbstractAnimal
{
  private:
	Brain *_brain;

  public:
	Cat();
	Cat(const Cat &orig);
	Cat &operator=(const Cat &orig);
	~Cat();

	virtual void makeSound(void) const;
	// base class가 abstract class일 때, 순수 가상 함수(pure virtual function)를
	// 구현해주지 않으면 이 유도 클래스 또한 abstract class가 된다.
	Brain *getBrain(void) const;
};

#endif
