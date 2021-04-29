#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void
    PhoneBook::showAllContactInfo(void)
{
    std::cout << "|===========================================|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|===========================================|" << std::endl;
    #if 1
    for (int i = 0; i < this->size; ++i)
        contacts[i].showInfo();
    #endif
    std::cout << "|===========================================|" << std::endl;
}

void
    PhoneBook::addContact(void)
{
    if (this->size == PHONEBOOK_SIZE_LIMIT)
        std::cout << WARN_FULL_CONTACTS << std::endl;
    else if (this->contacts[this->size].setInfo(this->size + 1))
        ++(this->size);
}

void
    PhoneBook::searchContact(void)
{
    int index;

    if (this->size == 0)
    {
        std::cout << WARN_NO_CONTACTS << std::endl;
        return ;
    }
    showAllContactInfo();
    std::cout << "* Enter index you want to search." << std::endl;
    std::cout << "> ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index > size)
        std::cout << "* WARNING: You input wrong index!" << std::endl;
    else if (index > 0 && index <= size)
        this->contacts[index - 1].showAllField();
    std::cin.clear(); // initialize error bit
    std::cin.ignore(INT_MAX, '\n'); // clear buffer memory
}