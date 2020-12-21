#include "StringDelegate.h"

#include <QLineEdit>
#include <QRegExpValidator>
#include "PhoneBookItem.h"


StringDelegate::StringDelegate(QObject* parent):
    QStyledItemDelegate(parent)
{
}

QWidget* StringDelegate::createEditor(QWidget* parent,
                                      const QStyleOptionViewItem& option,
                                      const QModelIndex& index) const
{
    Q_UNUSED(index)
    Q_UNUSED(option)
    QLineEdit* editor = new QLineEdit(parent);
    editor->setFrame(false);
    return editor;
}

void StringDelegate::setEditorData(QWidget* editor,
                                   const QModelIndex& index) const
{
    QLineEdit* e = static_cast<QLineEdit*>(editor);
    e->setText(index.model()->data(index, Qt::DisplayRole).toString());
}

void StringDelegate::updateEditorGeometry(QWidget* editor,
                                          const QStyleOptionViewItem& option,
                                          const QModelIndex& index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}

void StringDelegate::setModelData(QWidget* editor,
                                  QAbstractItemModel* model,
                                  const QModelIndex& index) const
{
    QLineEdit* e = static_cast<QLineEdit*>(editor);
    model->setData(index, e->text(), Qt::EditRole);
    emit model->dataChanged(index, index);
}
