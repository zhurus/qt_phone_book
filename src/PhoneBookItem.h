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
    static QRegExp getPhoneNumber_re();

    bool operator==(const PhoneBookItem& other) const;

    struct DescOrder
    {
        bool operator()(const PhoneBookItem& item1, const PhoneBookItem& item2);
    };

private:
    const static QRegExp phoneNumber_re;

    QString m_secondName;
    QString m_firstName;
    QString m_phoneNumber;
};
