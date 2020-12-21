#include "PhoneBook.h"
#include <QDebug>


int main(int argc, char** argv)
{
    PhoneBookItem item1;
    item1.setFirstName("Alexey");
    item1.setSecondName("Zhuravlev");
    item1.setPhoneNumber("+7-911-774-36-64");
    qDebug() << item1.getFirstName() << " "
             << item1.getSecondName() << " "
             << item1.getPhoneNumber();

    PhoneBookItem item2;
    item2.setFirstName("Alexey2");
    item2.setSecondName("Zhuravlev2");
    item2.setPhoneNumber("+7-911-774-36-65");
    qDebug() << item2.getFirstName() << " "
             << item2.getSecondName() << " "
             << item2.getPhoneNumber();

    PhoneBook phoneBook;
    phoneBook.push_back(item1);
    phoneBook.push_back(item2);
    return 0;
}
