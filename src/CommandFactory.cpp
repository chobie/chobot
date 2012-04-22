#include "CommandFactory.h"
#include "Send.h"

CommandFactory::CommandFactory(QObject *parent) : QObject(parent) {
}

Command *CommandFactory::createCommand(const char *name) {
	#include "find_command.h"
	return NULL;
}
