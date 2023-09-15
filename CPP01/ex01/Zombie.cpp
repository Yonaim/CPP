#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << this->_name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->_name << ": "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}