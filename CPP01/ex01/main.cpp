#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie *horde;
    const int N = 5;

    horde = zombieHorde(N, "zombie");
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}