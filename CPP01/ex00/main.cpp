#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie stack_zombie1("stackZombie1");
    randomChump("stackZombie2");

    Zombie *heap_zombie1 = newZombie("heapZombie1");
    Zombie *heap_zombie2 = new Zombie("heapZombie2");

    stack_zombie1.announce();
    heap_zombie1->announce();
    heap_zombie2->announce();

    delete heap_zombie1; // recommended
    // heap_zombie1->~Zombie(); // not recommended

    // heap_zombie1->announce(); // 어떻게 될까?
    // -> 컴파일은 가능. 그러나 이미 할당 해제한 메모리에 접근했으므로 런타임 중 segmentation fault로 간주됨
    // 이미 free()한 메모리 영역에 접근하는 것과 같은 맥락

    delete heap_zombie2;
}