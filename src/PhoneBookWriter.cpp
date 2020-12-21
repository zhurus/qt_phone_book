#include "PhoneBookWriter.h"

#include <QFile>
#include <QTextStream>

PhoneBookWriter::PhoneBookWriter(QObject* parent):
    QObject(parent)
{

}

void PhoneBookWriter::write(const PhoneBook& phonebook, const QString& filePath)
{
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for(const auto& item : phonebook) {
            if(item.getFirstName().isEmpty())
                continue;
            if(item.getSecondName().isEmpty())
                 continue;
            if(item.getPhoneNumber().isEmpty())
                continue;
            stream << item.getSecondName() << " "
                   << item.getFirstName() << " " <<
                      item.getPhoneNumber() << "\r\n";
        }
        file.close();
        m_lastStatus = SUCCESS;
    } else {
        m_lastStatus = FAILED;
    }
    emit done();
}

PhoneBookWriter::Status PhoneBookWriter::getLastStatus() const
{
    return m_lastStatus;
}
