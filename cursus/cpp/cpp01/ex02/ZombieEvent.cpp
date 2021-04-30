#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
    :type(std::string())
{
}

ZombieEvent::~ZombieEvent()
{
}

Zombie
    *ZombieEvent::newZombie(std::string const &_name)
{
    Zombie *ret;
    ret = new Zombie(_name, this->type);
    return (ret);
}

void
    ZombieEvent::setZombieType(std::string const &_type)
{
    this->type = _type;
}

Zombie
    *ZombieEvent::randomChump(void)
{
    Zombie *ret;

    ret = new Zombie(Zombie::genRandomName(LENGTH_ZOMBIE_NAME), this->type);
    ret->announce();
    return (ret);
}