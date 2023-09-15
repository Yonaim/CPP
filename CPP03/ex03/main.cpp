#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    
    DiamondTrap *dia_ptr = new DiamondTrap("dia_ptr"); // OK
    ScavTrap *scav_ptr = new DiamondTrap("scav_ptr");  // OK
    FragTrap *frag_ptr = new DiamondTrap("frag_ptr");  // OK
    ClapTrap *clap_ptr = new DiamondTrap("clap_ptr");  // OK

    std::cout << '\n';
    dia_ptr->attack("A");
    dia_ptr->whoAmI();
    dia_ptr->guardGate();
    dia_ptr->highFivesGuys();

    std::cout << '\n';
    scav_ptr->attack("B");
    // scav_ptr->whoAmI();
    scav_ptr->guardGate();
    // scav_ptr->highFiveGuys();

    std::cout << '\n';
    frag_ptr->attack("C");
    // frag_ptr->whoAmI();
    // frag_ptr->guardGate();
    frag_ptr->highFivesGuys();

    std::cout << '\n';
    clap_ptr->attack("D");
    // clap_ptr->whoAmI();
    // clap_ptr->guardGate();
    // clap_ptr->highFiveGuys();

    std::cout << '\n';
    dia_ptr->showStatus();
    scav_ptr->showStatus();
    frag_ptr->showStatus();
    clap_ptr->showStatus();

    std::cout << '\n';
    delete dia_ptr;
    delete scav_ptr;
    delete frag_ptr;
    delete clap_ptr;

    /* copy test */
    // DiamondTrap *ori = new DiamondTrap("orig");
    // DiamondTrap copied(*ori);

    // ori->showStatus();
    // copied.showStatus();

    // delete ori;
}
