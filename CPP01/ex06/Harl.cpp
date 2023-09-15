#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
    std::cout << "[ "
              << "DEBUG"
              << " ]" << '\n'
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << '\n'
              << "I really do!" << '\n'
              << std::endl;
}

void Harl::info()
{
    std::cout << "[ "
              << "INFO"
              << " ]" << '\n'
              << "I cannot believe adding extra bacon costs more money." << '\n'
              << "You didn't put enough bacon in my burger!" << '\n'
              << "If you did, I wouldn't be asking for more!" << '\n'
              << std::endl;
}

void Harl::warning()
{
    std::cout << "[ "
              << "WARNING"
              << " ]" << '\n'
              << "I think I deserve to have some extra bacon for free." << '\n'
              << "I've been coming for years whereas you started working here since last month." << '\n'
              << std::endl;
}

void Harl::error()
{
    std::cout << "[ "
              << "ERROR"
              << " ]" << '\n'
              << "This is unacceptable! I want to speak to the manager now." << '\n'
              << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*acts[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int i;
    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break;
    }

    switch (i)
    {
    case 0:
        (this->*acts[0])();
    case 1:
        (this->*acts[1])();
    case 2:
        (this->*acts[2])();
    case 3: {
        (this->*acts[3])();
        break;
    }
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
