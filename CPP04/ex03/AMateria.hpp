#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

// class ICharacter;

// A -> abstract
class AMateria
{
  private:
  protected:
	std::string _type;

  public:
	/*
	  추상 클래스는 객체를 만들 수 없지만, 추상 클래스를 구체화 한 구체
	  클래스(concrete class)의 경우 객체를 만들 수 있으며 해당 클래스의 객체를
	  만들 때 상속받은 추상 클래스의 생성자와 소멸자를 사용할 수 있으므로
	  추상 클래스의 생성자와 소멸자를 private로 두면 안된다.
	*/
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &orig);
	AMateria &operator=(const AMateria &orig);
	virtual ~AMateria();

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	// 어떤 파생 클래스더라도 clone을 반환할 수 있도록 순수 가상 함수로 선언
	virtual void use(ICharacter &target);
};

#endif
