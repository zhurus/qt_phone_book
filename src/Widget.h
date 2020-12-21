#pragma once

#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "PhoneBookReader.h"
#include "PhoneBookWriter.h"

#include "TableModel.h"


class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void addItem();
    void removeItem();
    void clear();
    void read();
    void save();

private:
    QHBoxLayout* mainLayout;
    QVBoxLayout* buttonsLayout;

    QPushButton* addBtn;
    QPushButton* removeBtn;
    QPushButton* clearBtn;
    QPushButton* readBtn;
    QPushButton* saveBtn;

    PhoneBookReader* reader = new PhoneBookReader(this);
    PhoneBookWriter* writer = new PhoneBookWriter(this);

    QTableView* tableView;
    TableModel* tableModel;
};

