#include "Command.h"

Command::Command(QObject *parent) : QObject(parent) {
}

void Command::start(QStringList &arguments) {
	Q_UNUSED(arguments);
}
