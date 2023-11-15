#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "---------- SMALL TEST ----------" << std::endl;
		int i_arr[] = {12, 7, 99, -3, 26, -45};
		
		Span sp1(10), sp2(3), sp3(1);
		for (size_t i = 0; i < sizeof(i_arr) / sizeof(int); i++)
		{
			sp1.addNumber(i_arr[i]);
			// sp2.addNumber(i_arr[i]); // Already full exception
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
		std::cout << "---------- BIG TEST ----------" << std::endl;
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return (0);
}