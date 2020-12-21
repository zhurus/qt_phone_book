#include "PhoneBookItem.h"


QString PhoneBookItem::getPhoneNumber() const
{
    return m_phoneNumber;
}

bool PhoneBookItem::setPhoneNumber(const QString& phoneNumber)
{
    static QRegExp phone_re(
                QStringLiteral("\\+{0,1}\\d{1,3}-\\d{3}-\\d{3}-\\d{2}-\\d{2}"));
    if(phone_re.exactMatch(phoneNumber)) {
        m_phoneNumber = phoneNumber;
        return true;
    }
    return false;
}

QString PhoneBookItem::getFirstName() const
{
    return m_firstName;
}

void PhoneBookItem::setFirstName(const QString& firstName)
{
    m_firstName = firstName;
}

QString PhoneBookItem::getSecondName() const
{
    return m_secondName;
}

void PhoneBookItem::setSecondName(const QString& secondName)
{
    m_secondName = secondName;
}

int PhoneBookItem::fieldsNumber()
{
    return 3;
}
