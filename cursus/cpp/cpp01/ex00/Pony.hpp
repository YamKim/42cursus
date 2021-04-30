#include <iostream>
#include <string>

class Pony
{
private:
    std::string name;

public:
    Pony(std::string const &name);
    ~Pony(void);
    void eat(); 
    void cry(); 
};