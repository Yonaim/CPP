#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

// FragTrap과 ScavTrap 클래스를 둘다 상속 받는 클래스가 ClapTrap 멤버를
// 중복해서 갖는 일을 피하기 위해 ClapTrap 클래스를 가상 상속(virtual inheritance)받는다.
// (FragTrap, ScavTrap 클래스 양쪽 다 가상 상속 받아야한다는 점을 주의할 것)
class ScavTrap : virtual public ClapTrap
{
  private:
  public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ScavTrap &ori);
    ScavTrap &operator=(const ScavTrap &ori);
    virtual ~ScavTrap();

    virtual void attack(const std::string &target);
    virtual void showStatus() const;
    void guardGate();
};

#endif