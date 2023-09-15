#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
  protected:
	std::string _type;

  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &orig);
	WrongAnimal &operator=(const WrongAnimal &orig);
	~WrongAnimal(); // 잘못된 점 2: 기초 클래스의 소멸자가 가상(virtual)
					// 소멸자가 아니다

	void makeSound(
		void) const; // 잘못된 점 1: 유도 클래스에서 오버라이딩될
					 // 함수가 가상(virtual) 함수로 선언되어 있지 않다
	const std::string &get_type(void) const;
	void set_type(const std::string type);
};

#endif
