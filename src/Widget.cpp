#include "Widget.h"

#include <QHeaderView>
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent):
    QWidget(parent)
{
    tableModel = new TableModel(this);
    tableView = new QTableView(this);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->setModel(tableModel);
    tableView->setSelectionBehavior(
                QAbstractItemView::SelectionBehavior::SelectRows);

    StringDelegate* delegate = new StringDelegate(this);
    tableView->setItemDelegate(delegate);
    setupUi();

    connect(addBtn, &QPushButton::clicked, this, &Widget::addItem);
    connect(removeBtn, &QPushButton::clicked, this, &Widget::removeItem);
    connect(clearBtn, &QPushButton::clicked, this, &Widget::clear);
    connect(readBtn, &QPushButton::clicked, this, &Widget::read);
    connect(saveBtn, &QPushButton::clicked, this, &Widget::save);
}

Widget::~Widget()
{
    delete buttonsLayout;
}

void Widget::setupUi()
{
    mainLayout = new QHBoxLayout(this);
    buttonsLayout = new QVBoxLayout;
    addBtn = new QPushButton(tr("Add item"), this);
    removeBtn = new QPushButton(tr("Remove item"), this);
    clearBtn = new QPushButton(tr("Clear"), this);
    readBtn = new QPushButton(tr("Read from file..."), this);
    saveBtn = new QPushButton(tr("Save to..."), this);

    setLayout(mainLayout);
    mainLayout->addWidget(tableView);
    mainLayout->addLayout(buttonsLayout);

    buttonsLayout->addWidget(addBtn);
    buttonsLayout->addWidget(removeBtn);
    buttonsLayout->addWidget(clearBtn);
    buttonsLayout->addWidget(readBtn);
    buttonsLayout->addWidget(saveBtn);
    buttonsLayout->addStretch();

    tableView->setMinimumSize(400, 300);

    setWindowTitle(tr("Phone book"));
}

void Widget::addItem()
{
    tableModel->addItem(PhoneBookItem());
}

void Widget::removeItem()
{
    QModelIndex index =  tableView->selectionModel()->currentIndex();
    tableModel->remove(index.row());
}

void Widget::clear()
{
    tableModel->clear();
}

void Widget::read()
{
#ifdef DEBUG
    QString file = QStringLiteral("../../data/example_phonebook.txt");
#else
    QString file = QFileDialog::getOpenFileName(
                nullptr,
                tr("Select phonebook file"),
                QStringLiteral("."),
                QStringLiteral("*.txt"));
#endif
    reader->read(file);
    tableModel->setPhonebook(reader->getPhoneBook());
}

void Widget::save()
{
#ifdef DEBUG
    QString file = QStringLiteral("../../data/example_phonebook_saved.txt");
#else
    QString file = QFileDialog::getSaveFileName(
                nullptr,
                tr("Save phonebook to file"),
                QStringLiteral("."),
                QStringLiteral("*.txt"));
#endif
    writer->write(tableModel->getPhonebook(), file);
}
