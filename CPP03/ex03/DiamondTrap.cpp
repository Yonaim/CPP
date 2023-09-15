#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("DIA_clap_name"), ScavTrap(), FragTrap(), _name("DIA")
{
    std::cout << "DiamondTrap " << this->_name << " created by default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
    std::cout << "DiamondTrap " << this->_name << " created by name constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ori) : ClapTrap(ori), ScavTrap(), FragTrap(), _name(ori._name)
{
    std::cout << "DiamondTrap " << this->_name << " created by copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ori)
{
    if (this != &ori)
    {
        this->_name = ori._name;
        this->_hp = ori._hp;
        this->_ep = ori._ep;
        this->_ad = ori._ad;
    }
    std::cout << "DiamondTrap " << this->_name << " created by copy assignment operator" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " deleted" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::showStatus() const
{
    std::cout << "\n====== Diamondtrap status ====="
              << "\n\tDiamondTrap Name: " << this->_name << "\n\tClapTrap Name: " << this->ClapTrap::_name << "\n\tHP: " << this->_hp
              << "\n\tEP: " << this->_ep << "\n\tAD: " << this->_ad << "\n===============================\n"
              << std::endl;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "DiamondTrap Name: " << this->_name << "\nClapTrap Name: " << this->ClapTrap::_name << std::endl;
}
