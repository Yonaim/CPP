#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  private:
  public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap &ori);
    ScavTrap &operator=(const ScavTrap &ori);
    virtual ~ScavTrap();

    virtual void attack(const std::string &target);
    // 부모 클래스로부터 상속 받은 함수를 재정의함으로써(=override) 다형성을 구현
    // 사실 자식 클래스의 함수 선언에 virtual 키워드를 붙여줄 필요는 없지만 명시해두는 편이 알기 편하다
    void guardGate();
    virtual void showStatus() const;
};

#endif