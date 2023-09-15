#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("S_DEFAULT")
{
    this->_hp = 100;
    this->_ep = 50;
    this->_ad = 20;
    std::cout << "ScavTrap " << this->_name << " created by default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
    this->_hp = 100;
    this->_ep = 50;
    this->_ad = 20;
    std::cout << "ScavTrap " << this->_name << " created by name constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ori) : ClapTrap(ori)
{
    std::cout << "ScavTrap " << this->_name << " created by copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ori)
{
    if (this != &ori)
    {
        this->_name = ori._name;
        this->_hp = ori._hp;
        this->_ep = ori._ep;
        this->_ad = ori._ad;
    }
    std::cout << "ScavTrap " << this->_name << " created by copy assignment operator" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " deleted" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_hp == 0 || this->_ep == 0)
        std::cout << "ScavTrap " << this->_name << " tried to attacks " << target << ", but couldn't." << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_ad
                  << " points of damage!" << std::endl;
        --this->_ep;
    }
}

void ScavTrap::showStatus() const
{
    std::cout << "\n======= Scavtrap status ======="
              << "\n\tName: " << this->_name << "\n\tHP: " << this->_hp
              << "\n\tEP: " << this->_ep << "\n\tAD: " << this->_ad << "\n===============================\n"
              << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode." << std::endl;
}