#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << this->_name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce() const
{
    std::cout << this->_name << ": "
              << "BraiiiiiiinnnzzzZ..." << std::endl;
}