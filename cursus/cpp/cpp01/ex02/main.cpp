#include <iostream>
#include <string>
#include "ZombieEvent.hpp"

int main(void)
{
    ZombieEvent lightZombie;
    ZombieEvent heavyZombie;

    std::cout << "=========Light Zombie..!==========="<< std::endl;
    lightZombie.randomChump();
    lightZombie.setZombieType("light");
    std::cout << "=========Light Zombie..!==========="<< std::endl;
    heavyZombie.randomChump();
    heavyZombie.setZombieType("heavy");
    #if 0
    Zombie b;
    a.announce();
    b.announce();
    #endif
    // delete=================================================

    return (0);
}