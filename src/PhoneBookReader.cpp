#include "PhoneBookReader.h"

#include <QTextStream>


PhoneBookReader::PhoneBookReader(QObject *parent) : QObject(parent)
{

}

PhoneBook PhoneBookReader::getPhoneBook() const
{
    return phoneBook;
}

PhoneBookReader::Status PhoneBookReader::read(const QString& filepath)
{
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit message(tr("Failed to open the file"));
        return FATAL_ERROR;
    }
    phoneBook.clear();
    QTextStream stream(&file);
    static QRegExp splitter("[\\s+\t+]+");
    Status ret = SUCCESS;
    int lineNumber = 0;
    nMistakes = 0;
    while(!stream.atEnd()) {
        lineNumber++;
        QString line = stream.readLine();
        QStringList list = line.split(splitter, Qt::SkipEmptyParts);
        if(list.size() == 0)
            continue;
        if(list.size() != PhoneBookItem::fieldsNumber()) {
            emit message(tr("Mistake occured: wrong number of fields in "
                            "line %1").arg(lineNumber));
            nMistakes++;
            ret = MISTAKES;
            continue;
        }
        PhoneBookItem item;
        item.setSecondName(list[0]);
        item.setFirstName(list[1]);
        if(!item.setPhoneNumber(list[2])) {
            emit message(tr("Mistake occured: incompatible phone number "
                            "of %1 %2").arg(list[0]).arg(list[1]));
            nMistakes++;
            continue;
        }

        phoneBook.push_back(item);
    }
    return ret;
}

int PhoneBookReader::getMistakesNumber() const
{
    return nMistakes;
}
