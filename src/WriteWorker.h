#pragma once

#include <QThread>
#include <QString>

#include "PhoneBookWriter.h"


class WriteWorker : public QThread
{
    Q_OBJECT
public:
    explicit WriteWorker(QObject *parent = nullptr);

	void setFilePath(const QString& path);
	void setPhoneBook(const PhoneBook& phoneBook);
	void run() override;

private:
	PhoneBookWriter* writer;
	QString m_path;
	PhoneBook m_phoneBook;
};

