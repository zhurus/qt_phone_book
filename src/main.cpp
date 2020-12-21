#include <QDebug>

#include "PhoneBookReader.h"
#include "logger.h"


int main(int argc, char** argv)
{
    PhoneBookReader reader;
    Logger* logger = new Logger;
    QObject::connect(&reader, SIGNAL(message(const QString&)),
                     logger, SLOT(printMessage(const QString&)));
    reader.read("../../data/example_phonebook.txt");
    for(auto item : reader.getPhoneBook()) {
        qDebug() << item.getSecondName() << " "
                 << item.getFirstName() << " " <<
                    item.getPhoneNumber();
    }
    return 0;
}
