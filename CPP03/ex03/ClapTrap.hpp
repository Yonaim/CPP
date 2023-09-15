#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
  protected:
    std::string _name;
    unsigned int _hp;
    unsigned int _ep;
    unsigned int _ad;

  public:
    ClapTrap();
    ClapTrap(const std::string name);
    ClapTrap(const ClapTrap &ori);
    ClapTrap &operator=(const ClapTrap &ori);
    virtual ~ClapTrap();

    virtual void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    virtual void showStatus() const;
};

#endif