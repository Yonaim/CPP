#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria; // 순환 참조(Circular Dependency)를 방지하기 위해 AMateria
				// 헤더를 include하는 대신 클래스만 전방 선언한다.

/*
순수 가상함수만을 갖는 추상 클래스를 인터페이스(Interface)라고 일컫는다.
*/

// I -> Interfaces
class ICharacter
{
  public:
	virtual ~ICharacter()
	{
	}
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
	virtual void showInventory(void) const = 0;
};

#endif
