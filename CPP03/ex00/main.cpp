#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("A");
    ClapTrap b("B");

    a.showStatus();
    b.showStatus();
    
    a.attack("Poor monster");
    a.showStatus();
	
    a.takeDamage(3);
    // a.takeDamage(20);
    a.showStatus();
    
    a.beRepaired(42);
    // for (int i = 0; i < 10; i++)
        // a.attack("Poor monster");
    a.showStatus();
}