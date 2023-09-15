#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("F_DEFAULT")
{
    this->_hp = 100;
    this->_ep = 100;
    this->_ad = 30;
    std::cout << "FragTrap " << this->_name << " created by default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    this->_hp = 100;
    this->_ep = 100;
    this->_ad = 30;
    std::cout << "FragTrap " << this->_name << " created by name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ori) : ClapTrap(ori)
{
    std::cout << "FragTrap " << this->_name << " created by copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ori)
{
    if (this != &ori)
    {
        this->_name = ori._name;
        this->_hp = ori._hp;
        this->_ep = ori._ep;
        this->_ad = ori._ad;
    }
    std::cout << "FragTrap " << this->_name << " created by copy assignment operator" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " deleted" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (this->_hp == 0 || this->_ep == 0)
        std::cout << "FragTrap " << this->_name << " tried to attacks " << target << ", but couldn't." << std::endl;
    else
    {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_ad
                  << " points of damage!" << std::endl;
        --this->_ep;
    }
}

void FragTrap::showStatus() const
{
    std::cout << "\n======= Fragtrap status ======="
              << "\n\tName: " << this->_name << "\n\tHP: " << this->_hp
              << "\n\tEP: " << this->_ep << "\n\tAD: " << this->_ad << "\n===============================\n"
              << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->_name << " positive high fives request!" << std::endl;
}