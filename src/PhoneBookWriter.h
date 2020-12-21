#pragma once

#include <QString>
#include <QObject>

#include "PhoneBook.h"


class PhoneBookWriter : public QObject
{
    Q_OBJECT
public:
    enum Status {
        SUCCESS,
        FAILED
    };

    PhoneBookWriter(QObject* parent = nullptr);

    void write(const PhoneBook& phonebook, const QString& filePath);
    Status getLastStatus() const;

signals:
    void done();

private:
    Status m_lastStatus;
};
