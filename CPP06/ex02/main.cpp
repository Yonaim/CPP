#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base *generate(void)
{
	int i = rand() % 3; // range 0 to 2
	// int i = rand() % 999; // range 0 to 999 (For random check)
	// std::cout << "Random number: " << i << std::endl;
	switch (i)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
	case 2:
		return (new C);
	}
	return (NULL);
}

// dynamic casting이 실패시 포인터는 NULL, 레퍼런스는 exception 반환

void identify(Base *p)
{
	std::cout << "The actual type (by Ptr): ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Hmm, Nothing. unfortunately..." << std::endl;
}

void identify(Base &p)
{
	std::cout << "The actual type (by Ref): ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(...) {}

	std::cout << "Hmm, Nothing. unfortunately..." << std::endl;
}


int main()
{
	srand(time(0));
	Base *instance_1 = generate();
	Base *instance_2 = generate();
	Base *instance_3 = generate();

	identify(instance_1);
	identify(instance_2);
	identify(instance_3);
	std::cout << "------------------------------\n";
	identify(*instance_1);
	identify(*instance_2);
	identify(*instance_3);

	delete instance_1;
	delete instance_2;
	delete instance_3;
}