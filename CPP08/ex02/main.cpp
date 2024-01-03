#include "MutantStack.hpp"
#include <iostream>
#include <vector>

void test_MutantStack()
{
	std::cout << "\n----------- TEST_MUTANTSTACK -----------\n" << std::endl;
	MutantStack<int> ms;

	ms.push(10);
	ms.push(7);
	ms.push(3);
	ms.push(-9);
	ms.push(42);
	ms.push(1);

	std::cout << "top: " << ms.top() << std::endl;
	std::cout << "size: " << ms.size() << std::endl;
	ms.pop();
	std::cout << "\nAfter pop... \n" << std::endl;
	std::cout << "top: " << ms.top() << std::endl;
	std::cout << "size: " << ms.size() << std::endl;

	ms.push(73);
	ms.push(5);
	ms.push(123456);
	
	std::cout << "\n--- print this container(normal) ---" << std::endl;
	MutantStack<int>::iterator it = ms.begin();
	for (; it != ms.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	std::cout << "\n--- print this container(reverse) ---" << std::endl;
	MutantStack<int>::reverse_iterator rit = ms.rbegin();
	for (; rit != ms.rend(); rit++)
	{
		std::cout << *rit << ", ";
	}
	std::cout << '\n';

	std::cout << "\n--- using const iterator ---" << std::endl;
	const MutantStack<int> &const_ms = ms;
	std::cout << *const_ms.begin() << std::endl;
	std::cout << *(const_ms.end() - 1) << std::endl;
	std::cout << *const_ms.rbegin() << std::endl;
	std::cout << *(const_ms.rend() - 1) << std::endl;
}

void test_vector()
{
	std::cout << "\n------------- TEST_VECTOR -------------\n" << std::endl;
	std::vector<int> v;

	v.push_back(10);
	v.push_back(7);
	v.push_back(3);
	v.push_back(-9);
	v.push_back(42);
	v.push_back(1);

	std::cout << "back: " << v.back() << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	v.erase(v.end() - 1);
	std::cout << "\nAfter erase element of end... \n" << std::endl;
	std::cout << "back: " << v.back() << std::endl;
	std::cout << "size: " << v.size() << std::endl;

	v.push_back(73);
	v.push_back(5);
	v.push_back(123456);
	
	std::cout << "\n--- print this container(normal) ---" << std::endl;
	std::vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << '\n';

	std::cout << "\n--- print this container(reverse) ---" << std::endl;
	std::vector<int>::reverse_iterator rit = v.rbegin();
	for (; rit != v.rend(); rit++)
	{
		std::cout << *rit << ", ";
	}
	std::cout << '\n';

	std::cout << "\n--- using const iterator ---" << std::endl;
	const std::vector<int> &const_v = v;
	std::cout << *const_v.begin() << std::endl;
	std::cout << *(const_v.end() - 1) << std::endl;
	std::cout << *const_v.rbegin() << std::endl;
	std::cout << *(const_v.rend() - 1) << std::endl;
}

int main()
{
	test_MutantStack();
	test_vector();
	return 0;
}