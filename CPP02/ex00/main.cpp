#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;    // 디폴트 생성자
    Fixed b(a); // 복사 생성자
    Fixed c;    // 디폴트 생성자

    c = b; // 복사 할당 연산자

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    // Fixed a;
    // a.setRawBits(42);

    // Fixed b(a);

    // a.setRawBits(99);

    // std::cout << a.getRawBits() << std::endl;
    // std::cout << b.getRawBits() << std::endl;

    return 0;
}
