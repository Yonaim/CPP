#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
  private:
    std::string _name;
    Weapon *_weapon;

  public:
    HumanB(std::string);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon &weapon);
};

#endif