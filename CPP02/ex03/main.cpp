#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
    Point a(Fixed(4), Fixed(0));
    Point b(Fixed(0), Fixed(4));
    Point c(Fixed(0), Fixed(0));
    
    Point p1(Fixed(1), Fixed(1)); // in 
    Point p2(Fixed(-1), Fixed(-1)); // out
    Point p3(Fixed(0), Fixed(0)); // on vertex
    Point p4(Fixed(2), Fixed(0)); // on edge

    std::cout << "BSP result1: " << bsp(a, b, c, p1) << std::endl;
    std::cout << "BSP result2: " << bsp(a, b, c, p2) << std::endl;
    std::cout << "BSP result3: " << bsp(a, b, c, p3) << std::endl;
    std::cout << "BSP result4: " << bsp(a, b, c, p4) << std::endl;
    return 0;
}
