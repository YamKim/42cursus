#include <string>
#include <iostream>
#include "Zombie.hpp"

#define LENGTH_ZOMBIE_NAME 10

class ZombieEvent
{
private:
    std::string type;

public:
    ZombieEvent();
    ~ZombieEvent();

    Zombie
        *newZombie(std::string const &_name);
    void
        setZombieType(std::string const &_type);
    Zombie
        *randomChump(void);
};