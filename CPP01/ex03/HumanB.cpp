#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
    // _weapon은 포인터 변수이므로 이러한 예외처리가 필요하다
    if (this->_weapon == NULL)
    {
        std::cout << this->_name << " doesn't have a weapon, can't attack" << std::endl;
        return;
    }

    // 포인터처럼 강제로 형변환(const -> non const)하여 값을 수정하는 것이 가능은 함. 그러나 권장되지 않음
    // const std::string &test1 = this->_weapon->getType();
    // std::string &test2 = (std::string &)test1;
    // test2 = "REPLACED WEAPON";

    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
