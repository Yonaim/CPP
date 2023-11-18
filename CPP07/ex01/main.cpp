#include "iter.hpp"
#include <string>
#include <iostream>
#include <cctype>

void multiply_hundred(int &n)
{
	n *= 100;
}

void plus_one(float &n)
{
	n += 1;
}

void to_upper(std::string &s)
{
	for (std::string::iterator it = s.begin(); it != s.end(); it++)
		*it = toupper(*it);
}

void coughing_print(const std::string &s)
{
	std::cout << "*cough* " << s << " *cough*" << std::endl;
}

int main()
{
	int i_arr[] = {1, 2, 3, 4, 5};
	float f_arr[] = {0.5, 0.7, -0.4};
	std::string s_arr[] = {"Hello", "world", "I'm", "yona"};
	const std::string const_s_arr[] = {"I'm", "sad", "because", "got cold..."};

	std::cout << "-------------- INT ARRAY TEST ------------------" << std::endl;
	iter(i_arr, sizeof(i_arr) / sizeof(int), multiply_hundred);
	for (size_t i = 0; i < sizeof(i_arr) / sizeof(int); i++)
		std::cout << "i_arr["<< i << "]: " << i_arr[i] << std::endl;

	std::cout << "--------------- FLOAT ARRAY TEST ----------------" << std::endl;

	::iter(f_arr, sizeof(f_arr) / sizeof(float), plus_one);
	for (size_t i = 0; i < sizeof(f_arr) / sizeof(float); i++)
		std::cout << "f_arr["<< i << "]: " << f_arr[i] << std::endl;
	
	std::cout << "-------------- STRING ARRAY TEST -------------" << std::endl;
	::iter(s_arr, sizeof(s_arr) / sizeof(std::string), to_upper);
	for (size_t i = 0; i < sizeof(s_arr) / sizeof(std::string); i++)
		std::cout << s_arr[i] << std::endl;

	std::cout << "------------ CONST STRING ARRAY TEST -------------" << std::endl;
	::iter(const_s_arr, sizeof(s_arr) / sizeof(std::string), coughing_print);
}