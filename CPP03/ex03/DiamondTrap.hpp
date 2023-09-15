#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
    std::string _name; // ClapTrap의 멤버 _name와는 별도의 공간을 가짐
    using FragTrap::_ad;
    using FragTrap::_hp;
    using ScavTrap::_ep;

  public:
    DiamondTrap();
    DiamondTrap(const std::string name);
    DiamondTrap(const DiamondTrap &ori);
    DiamondTrap &operator=(const DiamondTrap &ori);
    virtual ~DiamondTrap();

    // using ScavTrap::attack;
    virtual void attack(const std::string &target);
    virtual void showStatus() const;
    void whoAmI() const;
};

#endif