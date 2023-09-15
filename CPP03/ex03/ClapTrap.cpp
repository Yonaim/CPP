#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _name("C_DEFAULT"), _hp(10), _ep(10), _ad(0)
{
    std::cout << "ClapTrap " << this->_name << " created by default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
    std::cout << "ClapTrap " << this->_name << " created by name constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ori) : _name(ori._name), _hp(ori._hp), _ep(ori._ep), _ad(ori._ad)
{
    std::cout << "ClapTrap " << this->_name << " created by copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ori)
{
    if (this != &ori)
    {
        this->_name = ori._name;
        this->_hp = ori._hp;
        this->_ep = ori._ep;
        this->_ad = ori._ad;
    }
    std::cout << "ClapTrap " << this->_name << " created by copy assignment operator" << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " deleted" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_hp == 0 || this->_ep == 0)
        std::cout << "ClapTrap " << this->_name << " tried to attacks " << target << ", but couldn't." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_ad
                  << " points of damage!" << std::endl;
        --this->_ep;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->_name << " is taked damage and lose hit points " << amount << std::endl;
    if (this->_hp < amount)
        this->_hp = 0;
    else
        this->_hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hp == 0 || this->_ep == 0)
        std::cout << "ClapTrap " << this->_name << " tried to repair itself, but couldn't." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " is repaired and gain hit points " << amount << std::endl;
        this->_hp += amount;
        --this->_ep;
    }
}

void ClapTrap::showStatus() const
{
    std::cout << "\n======= Claptrap status ======="
              << "\n\tName: " << this->_name << "\n\tHP: " << this->_hp << "\n\tEP: " << this->_ep
              << "\n\tAD: " << this->_ad << "\n===============================\n"
              << std::endl;
}