#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

// serialize(직렬화): 데이터를 raw화 시키는 것. (오브젝트건, 뭐건 관계 없이 무조건 직렬적으로)
class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &orig);
	Serializer &operator=(const Serializer &orig);
    // For OCF. But doesn't make sence...

public:

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


#endif