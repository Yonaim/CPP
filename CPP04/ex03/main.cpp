#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void check()
{
	system("leaks Interface_n_recap");
}

int main()
{
	std::cout << '\n';
	std::cout << "=========== MATERIASOURCE TEST ===========\n" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(NULL);
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	{
		AMateria *extra = new Cure();
		src->learnMateria(extra);
		delete extra;
	}
	std::cout << '\n';
	// src->eraseMateria("ice"); // IMateriaSource 포인터이므로 인터페이스에
	// 선언되지 않은 함수는 사용할 수 없다

	std::cout << "============= CHARACTER TEST =============\n" << std::endl;
	ICharacter *me = new Character("me");
	me->showInventory();
	std::cout << '\n';

	me->equip(NULL);
	AMateria *materias[Character::inventory_size];
	for (int i = 0; i < Character::inventory_size; i++)
	{
		if (i < Character::inventory_size / 2)
			materias[i] = src->createMateria("ice");
		else
			materias[i] = src->createMateria("cure");
	}
	for (int i = 0; i < Character::inventory_size; i++)
		me->equip(materias[i]);
	me->showInventory();
	std::cout << '\n';

	{
		AMateria *ice_1 = src->createMateria("ice");
		AMateria *ice_2 = src->createMateria("ice");
		me->equip(ice_1);
		me->unequip(2);
		me->showInventory();
		me->equip(ice_2);
		me->showInventory();
		delete ice_1;
		delete materias[2];
	}
	std::cout << '\n';

	std::cout << "=========== DEEP COPY TEST ===========\n" << std::endl;
	{
		Character chara_orig("chara");
		AMateria *equip = new Ice();
		chara_orig.equip(equip);
		chara_orig.showInventory();

		Character chara_clone("chara_clone");
		chara_clone = chara_orig;
		chara_clone.showInventory();

		chara_orig.unequip(0);
		chara_orig.showInventory();
		chara_clone.showInventory();

		delete equip;
	}
	std::cout << '\n';

	std::cout << "=========== USE TEST ===========\n" << std::endl;
	ICharacter *bob = new Character("bob");
	for (int i = 0; i <= Character::inventory_size; i++)
	{
		me->use(i, *bob);
	}
	std::cout << '\n';


	std::cout << "=========== TEST FINISHED ===========\n" << std::endl;
	delete bob;
	delete me;
	delete src;

	// atexit(check);
	return 0;
}
