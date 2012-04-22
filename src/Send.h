#include "Command.h"

class Send : public Command {
	Q_OBJECT

public:
	Send(QObject *parent = 0);
	virtual void start(QStringList &arguments);
};

