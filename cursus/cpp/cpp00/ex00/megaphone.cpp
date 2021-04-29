#include <iostream>
#include <string>

#define DEFAULT_STRING "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << DEFAULT_STRING << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; ++i)
    {
        std::string str(argv[i]);
        for (int j = 0; j < (int)str.length(); ++j)
            std::cout << (char)std::toupper(str[j]);
        std::cout << std::endl;
    }
    return (0);
}