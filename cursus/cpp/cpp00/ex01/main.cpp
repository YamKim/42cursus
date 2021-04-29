#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    PhoneBook phoneBook;
    while (1)
    {
        std::cout << "* Enter command (ex. ADD, SEARCH, EXIT): " << std::endl;
        std::cout << "> ";
        std::string command;
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "* WARNING: You input wrong command!" << std::endl;
    }
    return (0);
}