#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "PhoneBook.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    PhoneBook ex;
    ex.addContact();
    ex.showContacts();

    return (0);
}