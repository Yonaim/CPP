#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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