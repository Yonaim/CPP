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

    // 자식 클래스가 멤버 함수를 재정의하여 사용할 수 있도록(=override할 수 있도록)
    // virtual 함수로 선언함으로써 다형성을 구현
    virtual void attack(const std::string &target);
    virtual void showStatus() const;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif