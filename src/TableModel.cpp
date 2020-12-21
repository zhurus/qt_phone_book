#include "TableModel.h"

TableModel::TableModel(QObject* parent):
    QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return m_phonebook.size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent)
    return PhoneBookItem::fieldsNumber();
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(index.row() >= m_phonebook.size())
        return QVariant();
    switch (index.column()) {
    case 0:
        return m_phonebook[index.row()].getSecondName();
        break;
    case 1:
        return m_phonebook[index.row()].getFirstName();
        break;
    case 2:
        return m_phonebook[index.row()].getPhoneNumber();
        break;
    default:
        break;
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex& index, const QVariant& value,
                         int role)
{
    if(role != Qt::EditRole)
        return false;
    if(index.row() >= m_phonebook.size())
        return false;
    switch (index.column()) {
    case 0:
    {
        m_phonebook[index.row()].setSecondName(value.toString());
        break;
    }
    case 1:
        m_phonebook[index.row()].setFirstName(value.toString());
        break;
    case 2:
    {
        bool success = m_phonebook[index.row()]
                .setPhoneNumber(value.toString());
        return success;
        break;
    }
    default:
        return false;
    }
    return true;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation,
                                int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Orientation::Vertical)
        return section + 1;
    else {
        switch (section) {
        case 0:
            return tr("Second name");
            break;
        case 1:
            return tr("First name");
            break;
        case 2:
            return tr("Phone");
            break;
        default:
            return QVariant();
        }
    }
}

void TableModel::setPhonebook(const PhoneBook& phonebook)
{
    beginResetModel();
    m_phonebook = phonebook;
    endResetModel();
}

PhoneBook TableModel::getPhonebook() const
{
    return m_phonebook;
}

void TableModel::addItem(const PhoneBookItem& item)
{
    int sz = m_phonebook.size();
    beginInsertRows(QModelIndex(), sz, sz);
    m_phonebook.push_back(item);
    endInsertRows();
}

void TableModel::remove(size_t pos)
{
    beginRemoveRows(QModelIndex(), pos, pos);
    m_phonebook.remove(pos);
    endRemoveRows();
}

void TableModel::clear()
{
    beginResetModel();
    m_phonebook.clear();
    endResetModel();
}
