#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QStringList>
#include "Response.h"

class Command : public QObject {
	Q_OBJECT

public:
	Command(QObject *parent = 0);
	virtual void start(QStringList &arguments);

signals:
	void finished(Response *response);
};

#endif
