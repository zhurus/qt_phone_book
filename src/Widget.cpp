#include "Widget.h"

#include <QHeaderView>
#include <QDebug>


Widget::Widget(QWidget *parent):
    QWidget(parent),
    mainLayout(new QHBoxLayout),
    buttonsLayout(new QVBoxLayout),
    tableView(new QTableView(this)),
    addBtn(new QPushButton(tr("Add item"), this)),
    removeBtn(new QPushButton(tr("Remove item"), this)),
    clearBtn(new QPushButton(tr("Clear"), this)),
    readBtn(new QPushButton(tr("Read from file..."), this)),
    saveBtn(new QPushButton(tr("Save to..."), this))
{
    setLayout(mainLayout);
    mainLayout->addWidget(tableView);
    mainLayout->addLayout(buttonsLayout);

    buttonsLayout->addWidget(addBtn);
    buttonsLayout->addWidget(removeBtn);
    buttonsLayout->addWidget(clearBtn);
    buttonsLayout->addWidget(readBtn);
    buttonsLayout->addWidget(saveBtn);
    buttonsLayout->addStretch();

    tableView->horizontalHeader()->setStretchLastSection(true);

    tableView->setMinimumSize(400, 300);

    connect(addBtn, &QPushButton::clicked, this, &Widget::addItem);
    connect(removeBtn, &QPushButton::clicked, this, &Widget::removeItem);
    connect(clearBtn, &QPushButton::clicked, this, &Widget::clear);
    connect(readBtn, &QPushButton::clicked, this, &Widget::read);
    connect(saveBtn, &QPushButton::clicked, this, &Widget::save);
}

Widget::~Widget()
{
    delete mainLayout;
    delete buttonsLayout;
}

void Widget::addItem()
{
    qDebug() << "Widget::addItem";
}

void Widget::removeItem()
{
    qDebug() << "Widget::removeItem";
}

void Widget::clear()
{
    qDebug() << "Widget::clear";
}

void Widget::read()
{
    qDebug() << "Widget::read";
}

void Widget::save()
{
    qDebug() << "Widget::save";
}
