#include <QObject>

class Command;

class CommandFactory : public QObject {
	Q_OBJECT

public:
	CommandFactory(QObject *parent = 0);
	Command *createCommand(const char *name);
};

