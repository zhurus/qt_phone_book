#pragma once

#include <QStyledItemDelegate>


class StringDelegate : public QStyledItemDelegate
{
public:
    StringDelegate(QObject* parent = nullptr);
	~StringDelegate() = default;

	QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
						  const QModelIndex &index) const override;
	void setEditorData(QWidget *editor,
					   const QModelIndex &index) const override;
	void updateEditorGeometry(QWidget *editor,
							  const QStyleOptionViewItem &option,
							  const QModelIndex &index) const override;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
					  const QModelIndex &index) const override;
};
