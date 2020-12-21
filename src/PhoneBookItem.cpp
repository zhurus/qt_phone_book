#include "PhoneBookItem.h"


const QRegExp PhoneBookItem::phoneNumber_re(
        QStringLiteral("\\+{0,1}\\d{1,3}-\\d{3,3}-\\d{3,3}-\\d{2,2}-\\d{2,2}"));


QString PhoneBookItem::getPhoneNumber() const
{
    return m_phoneNumber;
}

bool PhoneBookItem::setPhoneNumber(const QString& phoneNumber)
{
    if(phoneNumber_re.exactMatch(phoneNumber)) {
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

QRegExp PhoneBookItem::getPhoneNumber_re()
{
    return phoneNumber_re;
}

bool PhoneBookItem::operator==(const PhoneBookItem& other) const
{
    if(&other == this)
        return true;
    if(other.m_secondName != m_secondName)
        return false;
    if(other.m_firstName != m_firstName)
        return false;
    if(other.m_phoneNumber != m_phoneNumber)
        return false;
    return true;
}

bool PhoneBookItem::DescOrder::operator()(const PhoneBookItem& item1,
                                          const PhoneBookItem& item2)
{
    if(item1.m_secondName < item2.m_secondName)
        return true;
    else if(item1.m_secondName > item2.m_secondName)
        return false;

    if(item1.m_firstName < item2.m_firstName)
        return true;
    else if(item1.m_firstName > item2.m_firstName)
        return false;

    if(item1.m_phoneNumber < item2.m_phoneNumber)
        return true;
    else if(item1.m_phoneNumber > item2.m_phoneNumber)
        return false;
    return false;
}
