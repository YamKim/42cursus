#include "Zombie.hpp"

Zombie::Zombie()
    :name(std::string()), type(std::string())
{
}

Zombie::Zombie(std::string const &_name, std::string const &_type)
    :name(_name), type(_type)
{
}

Zombie::~Zombie()
{
}

void
    Zombie::announce(void)
{
    std::cout << "<" << this->name << " (" << this->type << ")> " ;
    std::cout << "Braiiiiiiinnnssss ..." << std::endl;
}

//https://stackoverflow.com/a/24586587
std::string
    Zombie::genRandomName(int size)
{
    std::string ret;

    static std::string cand = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 genRandomNum(rd());
    std::uniform_int_distribution<int> dist(0, cand.length());

    for (int i = 0; i < size; ++i)
        ret += cand[dist(genRandomNum)];
    std::cout << ret << std::endl;

    return (ret);
}