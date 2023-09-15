#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    // Fixed a(-10);
    // Fixed b(42);
    // std::cout << a + b << std::endl;
    // std::cout << a - b << std::endl;
    // std::cout << a * b << std::endl;
    // std::cout << b / a << std::endl;
    // std::cout << (a > b) << std::endl;
    // std::cout << (a < b) << std::endl;

    return 0;
}
