#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	int i_arr[] = {12, 7, 99, -3, 26, -45};
	for (size_t i = 0; i < sizeof(i_arr) / sizeof(int); i++)
	{
		v.push_back(i_arr[i]);
		d.push_back(i_arr[i]);
		l.push_back(i_arr[i]);
	}

	std::cout << "\n---------- print container values ------------" << std::endl;
	std::cout << "vector:\t";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << ", ";
	std::cout << '\n';

	std::cout << "deque:\t";
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
		std::cout << *it << ", ";
	std::cout << '\n';

	std::cout << "list:\t";
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << ", ";
	std::cout << '\n';

	try
	{
		std::cout << "\n------------ T = vector<int> --------------" << std::endl;
		std::vector<int>::const_iterator it;
		it = easyfind(v, 12); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(v, 99); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(v, -45); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(v, -30); // not exist
		std::cout << "success to find " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n------------ T = deque<int> --------------" << std::endl;
		std::deque<int>::const_iterator it;
		it = easyfind(d, 12); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(d, 99); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(d, -45); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(d, -30); // not exist
		std::cout << "success to find " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n------------ T = list<int> --------------" << std::endl;
		std::list<int>::const_iterator it;
		it = easyfind(l, 12); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(l, 99); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(l, -45); // exist
		std::cout << "success to find " << *it << std::endl;
		it = easyfind(l, -30); // not exist
		std::cout << "success to find " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
