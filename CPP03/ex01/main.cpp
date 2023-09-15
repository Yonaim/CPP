#include "ScavTrap.hpp"

int main()
{
    ClapTrap *parent1 = new ClapTrap("parent_1");
    // ScavTrap *parent2 = new ClapTrap("parent_2");
    // 자식 클래스의 포인터가 부모 클래스의 객체를 가리키는 것 -> NO

    ScavTrap *child1 = new ScavTrap("child_1");
    ClapTrap *child2 = new ScavTrap("child_2");
    // 부모 클래스의 포인터가 자식 클래스의 객체를 가리키는 것 -> OK
    // 이것이 바로 다형성!

    parent1->attack("A");

    child1->attack("B");
    child2->attack("C");
    // 과연 둘다 ScavTrap의 attack이 호출될까? (다형성이 제대로 구현되어 있다면 그래야 함)

    child1->guardGate();
    // child2->guardGate();
        // 부모 클래스의 포인터로 자식 클래스에게 유일한 멤버 함수를 호출할 수는 없다.
    // ((ScavTrap *)child2)->guardGate();
        // 자식 클래스가 유일하게 가지고 있는 멤버 함수를 호출하려면 포인터를 형변환하는 수밖에는 없다.

    parent1->showStatus();
    child1->showStatus();
    child2->showStatus();

    delete parent1;
    delete child1;
    delete child2;
    // 생성자 호출 순서는 부모 클래스 -> 자식 클래스순
    // 소멸자 호출 순서는 자식 클래스 -> 부모 클래스순
}