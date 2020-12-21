#pragma once

#include <QObject>
#include <QFile>
#include <memory>

#include "PhoneBook.h"



class PhoneBookReader : public QObject
{
    Q_OBJECT
public:
    enum Status {
        SUCCESS,
        MISTAKES,
        FATAL_ERROR
    };

    explicit PhoneBookReader(QObject *parent = nullptr);

    Status read(const QString& filepath);
    PhoneBook getPhoneBook() const;
    int getMistakesNumber() const;

signals:
    void message(const QString&);

private:
    PhoneBook phoneBook;
    int nMistakes;
};

