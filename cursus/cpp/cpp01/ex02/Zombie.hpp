#include <iostream>
#include <random>
#include <string>

class Zombie
{
private:
    std::string name;
    std::string type;

public:
    Zombie();
    Zombie(std::string const &name, std::string const &type);
    ~Zombie();

    void
        announce(void);
    static std::string
        genRandomName(int size);
};