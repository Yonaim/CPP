#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  public:
	static const int inventory_size = 4;

	Character();
	Character(std::string name);
	Character(const Character &orig);
	Character &operator=(const Character &orig);
	~Character();

	virtual std::string const &getName(void) const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);
	virtual void showInventory(void) const;

  private:
	std::string _name;
	AMateria *_inventory[inventory_size];

	void printName(void) const;
	void destroyAllInventory(void);
};

#endif
