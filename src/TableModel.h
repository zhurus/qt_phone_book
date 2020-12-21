#pragma once

#include <QAbstractTableModel>

#include "PhoneBook.h"


class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject* parent = nullptr);
    ~TableModel() = default;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index,
                  int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setPhonebook(const PhoneBook& phonebook);
    PhoneBook getPhonebook() const;

    void addItem(const PhoneBookItem& item);
    void remove(size_t pos);
    void clear();

private:
    PhoneBook m_phonebook;
};

