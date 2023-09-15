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
    virtual void showStatus() const;
    void guardGate();
};

#endif