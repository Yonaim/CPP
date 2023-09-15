#ifndef ABSTRACTANIMAL_HPP
#define ABSTRACTANIMAL_HPP

#include <string>

class AbstractAnimal
{
  protected:
	std::string _type;

  public:
	AbstractAnimal();
	AbstractAnimal(const AbstractAnimal &orig);
	AbstractAnimal &operator=(const AbstractAnimal &orig);
	virtual ~AbstractAnimal();

	virtual void makeSound(void) const = 0;
	const std::string &get_type(void) const;
	void set_type(const std::string type);
};

#endif
