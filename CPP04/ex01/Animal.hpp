#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  protected:
	std::string _type;

  public:
	Animal();
	Animal(const Animal &orig);
	Animal &operator=(const Animal &orig);
	virtual ~Animal();

	virtual void makeSound(void) const;
	const std::string &get_type(void) const;
	void set_type(const std::string type);
};

#endif
