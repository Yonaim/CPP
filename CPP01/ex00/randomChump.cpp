#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name)
{
    Zombie chump(name);
    chump.announce();
}