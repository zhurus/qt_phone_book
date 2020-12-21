#pragma once

#include <QString>
#include <QObject>

#include "PhoneBook.h"


class PhoneBookWriter : public QObject
{
    Q_OBJECT
public:
    PhoneBookWriter(QObject* parent = nullptr);

    bool write(const PhoneBook& phonebook, const QString& filePath);
};

