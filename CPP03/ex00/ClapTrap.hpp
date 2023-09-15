#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
  private:
    std::string _name;
    unsigned int _hp;
    unsigned int _ep;
    unsigned int _ad;

  public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap &ori);
    ClapTrap &operator=(const ClapTrap &ori);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void showStatus() const;
};


#endif