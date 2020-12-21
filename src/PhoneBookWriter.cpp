#include "PhoneBookWriter.h"

#include <QFile>
#include <QTextStream>

PhoneBookWriter::PhoneBookWriter(QObject* parent):
    QObject(parent)
{

}

bool PhoneBookWriter::write(const PhoneBook& phonebook, const QString& filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream stream(&file);
    for(const auto& item : phonebook) {
        stream << item.getSecondName() << " "
               << item.getFirstName() << " " <<
                  item.getPhoneNumber() << "\r\n";
    }
    file.close();
    return true;
}
