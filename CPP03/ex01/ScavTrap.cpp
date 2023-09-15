#include "ScavTrap.hpp"
#include <iostream>

// 자식 클래스의 생성자의 초기화 리스트에서 부모의 멤버 변수를 초기화할 수는 없음
// 아직 부모 생성자가 호출되지 않았기 때문
ScavTrap::ScavTrap() : ClapTrap()
// 기본적으로 ClapTrap의 디폴트 생성자를 호출하게 되어있지만 명시적으로 써둠
{
    this->_hp = 100;
    this->_ep = 50;
    this->_ad = 20;
    std::cout << "ScavTrap " << this->_name << " created by default constructor" << std::endl;
}

// 지정되어있는 생성자인 ClapTrap(name)만이 호출됨 (디폴트 생성자는 호출되지 않음)
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