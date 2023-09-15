#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	// 자식 클래스가 이 멤버들에 접근할 수 있도록 하기 위해 접근 제한자를 protected로 변경하였는데,
	// 이 대신 접근 제한자를 그대로 private로 두되, 자식 클래스가 getter/setter, 생성자와 같은 함수를 쓰도록 할 수도 있다.
		// (사실 객체위주 프로그래밍이 지향하는 캡슐화 측면에서 이것이 더 권장되는 방식이다. 
		// 그러나 과제 의도가 접근 제한자 protected에 대해 배워보라는 것 같아서...)
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
    // 상속 관계가 있는 클래스의 객체를 삭제할 때, 자원을 모두 알맞게 해제하기 위해서는
    // 꼭 '해당 클래스에 알맞은 소멸자'가 호출되어야 한다
    // 따라서 상속 관계가 있는 클래스의 소멸자에는 virtual 키워드를 꼭 붙여준다
    // (사실 이 예시 같은 경우에는 꼭 이리 해줄 필요는 없긴 하다.)

    virtual void attack(const std::string &target);
    virtual void showStatus() const;
    // virtual 키워드를 사용해 가상 함수로 선언함으로써,
    // 객체가 attak() 함수를 찾으려할 때 런타임시 찾도록(=동적 바인딩하도록)한다
      // 가상 함수(virtual function)는 파생 클래스에서 재정의할 것으로 기대하는 멤버 함수를 의미
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif