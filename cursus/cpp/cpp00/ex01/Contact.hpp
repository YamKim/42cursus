#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#define DEBUG_FILESTREAM 0
#define COUT_COLUMN_WIDTH 10

class Contact
{
private:
    int index;
    std::string
        info[11];
    static std::string
        fieldName[11];

    enum
        fieldNum
    {
        FirstName = 0,
        LastName,
        Nickname,
        Login,
        Address,
        Email,
        Phone,
        Birthday,
        FavoriteMeal,
        UnderwearColor,
        Secret
    };

public:
    Contact();
    ~Contact();

    bool
        setInfo(int index);
    void
        showInfo(void);
    void
        showAllField(void);
};