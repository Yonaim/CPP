#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// FragTrap과 ScavTrap 클래스를 둘다 상속 받는 클래스가 ClapTrap 멤버를
// 중복해서 갖는 일을 피하기 위해 ClapTrap 클래스를 가상 상속(virtual inheritance)받는다.
// (FragTrap, ScavTrap 클래스 양쪽 다 가상 상속 받아야한다는 점을 주의할 것)
class FragTrap : virtual public ClapTrap
{
  private:
  public:
    FragTrap();
    FragTrap(const std::string name);
    FragTrap(const FragTrap &ori);
    FragTrap &operator=(const FragTrap &ori);
    virtual ~FragTrap();

    virtual void attack(const std::string &target);
    virtual void showStatus() const;
    void highFivesGuys();
};

#endif