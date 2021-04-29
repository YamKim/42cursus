#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

# define WARN_FULL_CONTACTS "WARNING: The inventory is full!"
# define WARN_NO_CONTACTS "WARNING: The inventory is empty!"
# define PHONEBOOK_SIZE_LIMIT 8

class PhoneBook
{
private:
    Contact
        contacts[8];
    int
        size;
public:
    PhoneBook();
    ~PhoneBook();

    void showContacts();
    void addContact();
    void searchContact();
};

#endif