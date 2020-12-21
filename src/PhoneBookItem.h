#pragma once

#include <QString>
#include <QRegExp>


class PhoneBookItem
{
public:
    PhoneBookItem() = default;
    ~PhoneBookItem() = default;

    QString getPhoneNumber() const;
    bool setPhoneNumber(const QString& phoneNumber);

    QString getFirstName() const;
    void setFirstName(const QString& firstName);

    QString getSecondName() const;
    void setSecondName(const QString& secondName);

    static int fieldsNumber();

private:
    QString m_secondName;
    QString m_firstName;
    QString m_phoneNumber;
};
