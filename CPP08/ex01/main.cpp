#include "Span.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <limits>

int main()
{
	try
	{
		std::cout << "\n---------- GENERAL TEST ----------\n" << std::endl;
		int arr[] = {12, 7, 99, -3, 26, -45};
		
		Span sp1(10), sp2(3), sp3(1);
		for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			sp1.addNumber(arr[i]);
			// sp2.addNumber(arr[i]); // Already full exception
		}

		sp3.addNumber(42);
		// sp3.shortestSpan(); // There is no span exception
		// sp3.longestSpan(); // There is no span exception

		std::cout << "shortestSpan: " << sp1.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n---------- RANGE ADD TEST ----------\n" << std::endl;

		Span sp1(100), sp2(100), sp3(100), sp4(100);

		int arr[] = {1, 5, 7, 2, 9, 4, 3};
		std::vector<int> v;
		std::deque<int> d;
		std::list<int> l;
		for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			v.push_back(arr[i]);
			d.push_back(arr[i]);
			l.push_back(arr[i]);
		}

		// sp1.addRange(std::begin(arr), std::end(arr)); // std::begin, std::end의 경우 C++11 표준.
		sp2.addRange(v.begin(), v.end());
		sp3.addRange(d.begin(), d.end());
		sp4.addRange(l.begin(), l.end());
		
		sp1.showStoredIntegers();
		sp2.showStoredIntegers();
		sp3.showStoredIntegers();
		sp4.showStoredIntegers();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		std::cout << "\n---------- BIG TEST ----------\n" << std::endl;

		Span sp(20000);
		std::vector<int> v;
		srand(time(0));
		for (size_t i = 0; i < 10000; i++)
			v.push_back(rand() % std::numeric_limits<int>::max() + 1); // 0 ~ INT_MAX

		sp.addRange(v.begin(), v.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}