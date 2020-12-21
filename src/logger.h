#pragma once

#include <QObject>
#include <QDebug>


class Logger : public QObject
{
	Q_OBJECT
public:
	Logger(): QObject() {}
	~Logger() = default;

public slots:
	void printMessage(const QString& message) {
		qDebug() << message;
	}
};
