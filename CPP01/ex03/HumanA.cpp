#include "HumanA.hpp"

// HumanA에는 데이터 멤버로 레퍼런스 변수가 있는데, 레퍼런스는 선언과 동시에 초기화를 해야하므로
// 생성자에서 초기화 리스트(initializer list)를 사용해야 한다.
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
