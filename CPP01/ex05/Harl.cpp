#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << "DEBUG" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO" << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING" << std::endl;
}

void Harl::error()
{
    std::cout << "ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*acts[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    // acts는 일반적인 함수 포인터(pointer-to-function)가 아닌 멤버 함수 포인터(pointer-to-member-function)의 배열
    // 클래스의 멤버 함수를 안전하게 참조하는 방법으로서 멤버 함수 포인터가 활용된다.

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*acts[i])();
        // 멤버 함수 포인터를 사용해 함수를 호출하려면 역참조 연산자 *를 사용해 실제 함수의 주소를 얻어야한다.
    }
}
