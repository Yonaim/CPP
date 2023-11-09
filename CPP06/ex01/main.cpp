#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.num = 123;
	data.str = "hello";

	Data *data_ptr = &data;
	std::cout << "--------- Original Pointer -------- " << std::endl;
	std::cout << "num: " << data_ptr->num << std::endl;
	std::cout << "str: " << data_ptr->str << std::endl;

	uintptr_t uint_ptr = Serializer::serialize(data_ptr);
	Data *data_ptr2 = Serializer::deserialize(uint_ptr);

	std::cout << "--------- Deserialized Pointer -------- " << std::endl;
	std::cout << "num: " << data_ptr2->num << std::endl;
	std::cout << "str: " << data_ptr2->str << std::endl;

	std::cout << "--------- Change Test -------- " << std::endl;
	data_ptr2->str = "world";
	std::cout << "str: " << data_ptr->str << std::endl;

	std::cout << "--------- Check Value in variables -------- " << std::endl;
	std::cout << std::hex << uint_ptr << std::endl;
	std::cout << data_ptr << std::endl;
	std::cout << data_ptr2 << std::endl;
}
