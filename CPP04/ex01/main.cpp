#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void check()
{
	system("leaks i_dont_want_to_set_the_world_on_fire");
}

int main()
{
	std::cout << "\n=============== CREATE ANIMALS ===============\n"
			  << std::endl;

	const size_t n_animal = 6;
	Animal *animals[n_animal];
	for (size_t i = 0; i < n_animal; ++i)
	{
		if (i < n_animal / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << '\n';
	}

	std::cout << "\n================ BRAIN TEST ================\n"
			  << std::endl;

	Cat *cat_orig = (Cat *)(animals[n_animal / 2]);

	std::string deep_copy_check_str = "deep copy check";
	cat_orig->getBrain()->setIdea(0, "hungry");
	cat_orig->getBrain()->setIdea(1, "i want fish");
	cat_orig->getBrain()->setIdea(2, deep_copy_check_str);
	cat_orig->getBrain()->setIdea(3, "i hate dog");

	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "cat_orig: ideas[" << i
				  << "]: " << cat_orig->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << '\n';

	cat_orig->getBrain()->setIdea(0, "full");
	deep_copy_check_str = "replaced";
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "cat_orig: ideas[" << i
				  << "]: " << cat_orig->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << '\n';

	std::cout << "\n============= OBJECT DEEP COPY TEST =============\n"
			  << std::endl;

	Cat cat_copy(*cat_orig);

	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "cat_orig: ideas[" << i
				  << "]: " << cat_orig->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << '\n';
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "cat_copy: ideas[" << i
				  << "]: " << cat_copy.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << '\n';

	cat_orig->getBrain()->setIdea(0, "replaced");

	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "cat_orig: ideas[" << i
				  << "]: " << cat_orig->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << '\n';
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout << "cat_copy: ideas[" << i
				  << "]: " << cat_copy.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << '\n';

	std::cout << "\n============== TEST FINISHED ==============\n" << std::endl;

	for (size_t i = 0; i < n_animal; ++i)
	{
		delete animals[i];
		std::cout << '\n';
	}

	// atexit(check);
	return 0;
}