#include "Pony.hpp"

Pony::Pony(std::string const &name): 
    name(name)
{
    std::cout << "Pony name: " << this->name << std::endl;
}

Pony::~Pony(void)
{
    std::cout << this->name << " deconstructed." << std::endl;
}

void Pony::eat()
{
    std::cout << "I'm eating yummy carrot." << std::endl;
}

void Pony::cry()
{
    std::cout << "Whinny r//" << std::endl;
}