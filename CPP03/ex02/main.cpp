#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // 지금까지와 마찬가지로 부모 클래스 포인터로 자식 클래스 객체를 접근하는 것이 가능하다
    FragTrap *Frag_child1 = new FragTrap("Frag_child_1"); // OK
    ClapTrap *Frag_child2 = new FragTrap("Frag_child_2"); // OK

    // 같은 부모 클래스로부터 상속받은 자식 클래스들끼리는 서로의 포인터를 사용할 수 없다.
    // ScavTrap *Frag_child3= new FragTrap("Frag_child_3"); // NO
    // FragTrap *Scav_child1 = new ScavTrap("Scav_child_1"); // NO

    Frag_child1->attack("A");
    Frag_child2->attack("B");

    Frag_child1->highFivesGuys();
    // Frag_child2->highFivesGuys(); // NO

    Frag_child1->showStatus();
    Frag_child2->showStatus();

    delete Frag_child1;
    delete Frag_child2;
}