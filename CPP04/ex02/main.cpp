#include "AbstractAnimal.hpp"
#include "AbstractCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void check()
{
	system("leaks abstract_class");
}

int main()
{
	// AbstractAnimal *abstract_animal = new AbstractAnimal();
	// AbstractCat *abstract_cat = new AbstractCat();
	// 가상 클래스의 인스턴스는 만들 수 없다
	AbstractAnimal *cat = new Cat();
	AbstractAnimal *dog = new Dog();
	std::cout << '\n';

	// abstract_animal->makeSound();
	// abstract_cat->makeSound();
	cat->makeSound();
	dog->makeSound();
	std::cout << '\n';

	std::cout << cat->get_type() << '\n';
	cat->set_type("veeeeery cute Cat");
	std::cout << cat->get_type() << '\n';
	std::cout << '\n';

	delete cat;
	delete dog;

	atexit(check);
}