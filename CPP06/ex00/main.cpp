#include "ScalarConverter.hpp"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

void printForCheck()
{
    std::cout << "------------ Print for check... ------------" << std::endl;

// check valid float values
    // std::cout << 42.f << std::endl;
    // // std::cout << .f << std::endl;
    // std::cout << .42f << std::endl;
    // // std::cout << 21f << std::endl;

// check valid double values
    // std::cout << 42.42 << std::endl;
    // std::cout << 42. << std::endl;
    // std::cout << .42 << std::endl;
    // std::cout << . << std::endl;

// pseudo values of float
    // float f1 = NAN;
    // float f2 = INFINITY;
    // float f3 = -INFINITY;
    // std::cout << f1 << std::endl;
    // std::cout << f2 << std::endl;
    // std::cout << f3 << std::endl;

// pseudo values of double
    // double d1 = NAN;
    // double d2 = INFINITY;
    // double d3 = -INFINITY;
    // std::cout << isinf(d3) << std::endl;

// check range of primitive types
    std::cout.unsetf(std::ios_base::floatfield);
	std::cout << std::setprecision(6);
    std::cout << "int max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "float max: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "double max: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "long double max: " << std::numeric_limits<long double>::max() << std::endl;
}

/*
Possible value for each Primitive type (부동소수점의 경우, 정확한 값은 아님)
- char: -128 ~ 127
- int: -2147483648 ~ 2147483647
- float: 340282346638528859811704183484516925440 (약 3.40282e+38)
- double: 약 1.79769e+308
- long double:	약 1.18973e+4932 (16byte, intelMac),
                약 1.79769e+308 (8byte, siliconMac)
*/

/*
부동소수점 표현 특성상, 아주 큰 값이나 작은 값일수록 오차가 커진다.
(한정된 비트 수로 표현되는 가수부의 n제곱 형태로 수를 나타내기 때문.)
이에 따라 본 프로그램도 인자로 들어온 literal의 값이 아주 크거나 작음에 따라 그 값을 제대로 표현하지 못하는 한계가 있다.
이는 _actual값을 출력할 때 직접적으로 확인할 수 있다.
*/

/*
<CPP06 ex00 과제에 대한 사족>

casting(형변환)을 처음 소개하고, 이를 이용한 간단한 프로그램을 만들라고 하는 과제이므로
사실 어려울 것이 없음. 그냥 요구사항 그대로 이행하면 됨.

1. You have to first detect the type of the literal passed as parameter
2. convert it from string to its actual type
3 then convert it explicitly to the three other data types
4. Lastly, display the results as shown below

스칼라 타입과 프리미티브 타입은 다르며, 과제에서 일컫는 type은 스칼라 타입이라는 점을 분명히 인지해야 함.
(이 점에서 actual value를 일괄적으로 특정 primitive 자료형으로 저장해도 무방하다고 판단했음.)

다만 후반부에서 overflow나 numeric limits를 언급하는 것을 보면 갑자기 생뚱맞게 primitive type으로 취급하는 듯한데,
과제가 엄밀하지 않다는 느낌을 지울 수는 없긴 함. 둘 중 하나만 확실히 하라고~

*/
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "invalid input" << std::endl;
        return (1);
    }

    std::string literal(argv[1]);
    ScalarConverter::convert(literal);
	ScalarConverter::printDetectedResult();
	// printForCheck();
}
