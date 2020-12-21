#include "WriteWorker.h"


WriteWorker::WriteWorker(QObject *parent):
	QThread(parent),
	writer(new PhoneBookWriter(this))
{
}

void WriteWorker::setFilePath(const QString& path)
{
	m_path = path;
}

void WriteWorker::setPhoneBook(const PhoneBook& phoneBook)
{
	m_phoneBook = phoneBook;
}

void WriteWorker::run()
{
	writer->write(m_phoneBook, m_path);
}
