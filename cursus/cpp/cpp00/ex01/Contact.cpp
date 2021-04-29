#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::fieldName[11] = {
    "First Name",
    "Last Name",
	"Nickname",
	"Login",
	"Address",
	"E-mail",
	"Phone",
	"Birthday",
	"Favorite Meal",
	"Underwear Color",
	"Darkest Secret"
};

bool Contact::setInfo(int index)
{
    #if DEBUG_FILESTREAM
    std::ifstream readFile("contact.txt"); //================================
    #endif
    this->index = index;
    for (int i = FirstName; i <= Secret; ++i)
    {
        std::cout << "** Input " << fieldName[i] << ":" << std::endl;
        std::cout << ">> ";
        #if !DEBUG_FILESTREAM
        std::getline(std::cin, this->info[i]);
        #endif
        #if DEBUG_FILESTREAM
        if (readFile.eof())
            return (false);
        char line[100];
        memset(line, 0, 100);
        readFile.getline(line, 10);
        for (int j = 0; j < 10; ++j)
        {
            this->info[i][j] = line[j];
        }
        std::cout << this->info[i] << std::endl;
        #endif
    }
    #if DEBUG_FILESTREAM
    readFile.close();
    #endif
    return (true);
}

void Contact::showInfo(void)
{
    std::cout << "|" << std::setw(COUT_COLUMN_WIDTH) << this->index;
    for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->info[i].length() > COUT_COLUMN_WIDTH)
			std::cout << this->info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(COUT_COLUMN_WIDTH) << this->info[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::showAllField(void)
{
   std::cout << "| index: " << this->index << " ---------------------------------|" << std::endl;
   for (int i = FirstName; i <= Secret; ++i)
        std::cout << "| " << fieldName[i] << ": " << this->info[i] << std::endl;
   std::cout << "|------------------------------------------|" << std::endl;
}