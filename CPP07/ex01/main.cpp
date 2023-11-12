#include "iter.hpp"
#include <string>
#include <iostream>

void multiply_hundred(int &n)
{
	n *= 100;
}

void plus_one(float &n)
{
	n += 1;
}

void coughing_print(std::string &s)
{
	std::cout << "*cough* " << s << " *cough*" << std::endl;
}

int main()
{
	int i_arr[] = {1, 2, 3, 4, 5};
	float f_arr[] = {0.5, 0.7, -0.4};
	std::string s_arr[] = {"Hello", "world", "I'm", "yona"};

	::iter(i_arr, sizeof(i_arr) / sizeof(int), multiply_hundred);
	for (int i = 0; i < sizeof(i_arr) / sizeof(int); i++)
		std::cout << "i_arr["<< i << "]: " << i_arr[i] << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	::iter(f_arr, sizeof(f_arr) / sizeof(float), plus_one);
	for (int i = 0; i < sizeof(f_arr) / sizeof(float); i++)
		std::cout << "f_arr["<< i << "]: " << f_arr[i] << std::endl;

	std::cout << "--------------------------------------" << std::endl;

	::iter(s_arr, sizeof(s_arr) / sizeof(std::string), coughing_print);
}