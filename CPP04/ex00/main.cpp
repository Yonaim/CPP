#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void check()
{
	system("leaks Polymorphism");
}

int main()
{
	std::cout << "=========== CORRECT CLASS TEST ===========\n" << std::endl;

	const Animal *animal = new Animal();
	const Dog *dog = new Dog();
	const Cat *cat = new Cat();
	std::cout << std::endl;

	std::cout << dog->get_type() << " " << std::endl;
	std::cout << cat->get_type() << " " << std::endl;
	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound(); // will output the dog sound
	cat->makeSound(); // will output the cat sound
	std::cout << std::endl;

	std::cout << "=========== WRONG CLASS TEST ============\n" << std::endl;

	const WrongAnimal *wrong_animal = new WrongAnimal();
	// const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << std::endl;

	// std::cout << wrong_cat->get_type() << " " << std::endl;
	std::cout << std::endl;

	wrong_animal->makeSound();
	// wrong_cat
		// ->makeSound(); // will output the sound of wrong animal (잘못된 점 1)
	std::cout << std::endl;

	std::cout << "=============== TEST FINISHED ===============\n" << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_animal;
	// delete wrong_cat; // wrong_animal의 소멸자만 호출된다 (잘못된 점 2)

	// atexit(check);
	return 0;
}