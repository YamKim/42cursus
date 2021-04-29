#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void
    PhoneBook::showContacts(void)
{
    std::cout << "|===========================================|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|===========================================|" << std::endl;
    for (int i = 0; i < this->size; ++i)
    {
        contacts[i].showInfo();
    }
    std::cout << "|===========================================|" << std::endl;
}

void
    PhoneBook::addContact()
{
    if (this->size == PHONEBOOK_SIZE_LIMIT)
        std::cout << WARN_FULL_CONTACTS << std::endl;
    else if (this->contacts[this->size].setInfo(this->size + 1))
        ++(this->size);
}