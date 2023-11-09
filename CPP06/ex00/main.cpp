#include <iostream>
#include <limits>
#include <string>
#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "invalid input" << std::endl;
		return (1);
	}

	// std::cout << std::setprecision(std::numeric_limits<float>::digits10) << 42 << std::endl;

	std::string literal(argv[1]);
	ScalarConverter::convert(literal);
	
	// float f1 = NAN;
	// float f2 = INFINITY;
	// float f3 = -INFINITY;
	// std::cout << f1 << std::endl;
	// std::cout << f2 << std::endl;
	// std::cout << f3 << std::endl;

	// double d1 = NAN;
	// double d2 = INFINITY;
	// double d3 = -INFINITY;
	// std::cout << isinf(d3) << std::endl;


	// std::cout << 42.f << std::endl;
	// // std::cout << .f << std::endl;
	// std::cout << .42f << std::endl;
	// // std::cout << 21f << std::endl;


	// std::cout << 42.42 << std::endl;
	// std::cout << 42. << std::endl;
	// std::cout << .42 << std::endl;
	// std::cout << . << std::endl;

	// std::cout << (int)std::numeric_limits<char>::min() << std::endl;
	// std::cout << (int)std::numeric_limits<char>::max() << std::endl;
	// std::cout << std::numeric_limits<float>::min() << std::endl;
	// std::cout << std::numeric_limits<float>::max() << std::endl;
	// std::cout << std::numeric_limits<double>::min() << std::endl;
	// std::cout << std::numeric_limits<double>::max() << std::endl;

}