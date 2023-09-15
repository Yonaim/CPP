#include "Character.hpp"
#include <iostream>

Character::Character() : _name("DEFAULT")
{
	for (size_t i = 0; i < inventory_size; ++i)
		_inventory[i] = NULL;
	std::cout << "Character '" << _name << "' created" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (size_t i = 0; i < inventory_size; ++i)
		_inventory[i] = NULL;
	std::cout << "Character '" << _name << "' created" << std::endl;
}

Character::Character(const Character &orig)
{
	*this = orig;
}

Character &Character::operator=(const Character &orig)
{
	_name = orig._name;
	for (size_t i = 0; i < inventory_size; ++i)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (orig._inventory[i])
			_inventory[i] = orig._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character()
{
	destroyAllInventory();
	std::cout << "Character '" << _name << "' deleted" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	printName();
	if (m == NULL)
	{
		std::cout << "equip failed: invalid equipment" << std::endl;
		return;
	}
	for (size_t i = 0; i < inventory_size; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			std::cout << "equip succeed: inventory #" << i << " '"
					  << m->getType() << "'" << std::endl;
			return;
		}
		else if (_inventory[i] == m)
		{
			std::cout << "equip failed: already equiped equipment" << std::endl;
			return;
		}
	}
	std::cout << "equip failed: inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	printName();
	if (!(0 <= idx && idx < inventory_size))
	{
		std::cout << "unequip failed: index out of range" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "unequip failed: inventory #" << idx << " does not exist"
				  << std::endl;
		return;
	}
	_inventory[idx] = NULL;
	std::cout << "unequip succeed: inventory #" << idx << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	printName();
	if (!(0 <= idx && idx < inventory_size))
	{
		std::cout << "use failed: index out of range" << std::endl;
		return;
	}
	if (_inventory[idx] == NULL)
	{
		std::cout << "use failed: inventory #" << idx << " does not exist"
				  << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}

void Character::destroyAllInventory(void)
{
	for (size_t i = 0; i < inventory_size; ++i)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	printName();
	std::cout << "Everything in inventory has been destroyed" << std::endl;
}

void Character::printName(void) const
{
	std::cout << "[" << _name << "]: ";
}

void Character::showInventory(void) const
{
	printName();
	std::cout << '\n';
	for (size_t i = 0; i < inventory_size; ++i)
	{
		std::string item_str;
		if (_inventory[i] == NULL)
			item_str = "(empty)";
		else
			item_str = "'" + _inventory[i]->getType() + "'";
		std::cout << "\tinventory #" << i << ' ' << item_str << '\n';
	}
	std::cout << std::flush;
}
