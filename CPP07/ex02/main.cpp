#include "Array.hpp"
#include <iostream>

void print_arr(const Array<int> &arr, std::string name)
{
	for (int i = 0; i < arr.size(); i++)
		std::cout << name << "["<< i << "]: " << arr[i] << std::endl;
}

int main()
{
	std::cout << "------------------ construct & access test -----------------------" << std::endl;
	Array<int> arr(5);
	print_arr(arr, "arr");
	std::cout << '\n';
	for (int i = 0; i < arr.size(); i++)
		arr[i] = i + 1;
	print_arr(arr, "arr");

	try
	{
		// (void)arr[-1]; // out of range
		// (void)arr[5];
		// (void)arr[10]; // out of range
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exeption: " << e.what() << '\n';
	}

	std::cout << "----------------- copy test ----------------------" << std::endl;
	Array<int> copied_arr(arr);
	print_arr(copied_arr, "copied_arr");

	copied_arr[3] = 999;
	std::cout << "\nAfter change 'copied_arr[3]'...\n" << std::endl;
	print_arr(copied_arr, "copied_arr");
	print_arr(arr, "arr");
	
	std::cout << "---------------- const test ----------------------" << std::endl;
	const Array<int> &const_arr = arr;
	std::cout << "const_arr" << "["<< 3 << "]: " << const_arr[3] << std::endl; // reading is ok
	// const_arr[3] = 999; // error
}
