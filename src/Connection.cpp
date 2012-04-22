#include "Connection.h"
#include "CommandParser.h"
#include "CommandFactory.h"
#include "Command.h"

#include <QTcpSocket>
#include <iostream>

Connection::Connection(QTcpSocket *socket, QObject *parent) :
	QObject(parent) {

	m_socket = socket;
	m_commandParser = new CommandParser(socket, this);
	m_commandFactory = new CommandFactory(this);
	m_command = NULL;
	m_pageSuccess = true;
	m_commandWaiting = false;
	m_pageLoadingFromCommand = false;
	m_pendingResponse = NULL;

	connect(m_socket, SIGNAL(readyRead()), m_commandParser, SLOT(checkNext()));
	connect(m_commandParser, SIGNAL(commandReady(QString, QStringList)), this, SLOT(commandReady(QString, QStringList)));
	connect(m_socket, SIGNAL(disconnected()),m_socket, SLOT(deleteLater()));
}


void Connection::commandReady(QString commandName, QStringList arguments) {
	m_commandName = commandName;
	m_arguments = arguments;

	startCommand();
}

void Connection::startCommand() {
	m_commandWaiting = false;

	if (m_pageSuccess) {
		m_command = m_commandFactory->createCommand(m_commandName.toAscii().constData());
		if (m_command) {
			//std::cout << "command :" << std::endl;
			connect(m_command,
				SIGNAL(finished(Response *)),
				this,
				SLOT(finishCommand(Response *)));
			m_command->start(m_arguments);
		} else {
			std::cout << "unkonown command :" << std::endl;
			QString failure = QString("[Capybara WebKit] Unknown command: ") +  m_commandName + "\n";
			writeResponse(new Response(false, failure));
		}
	} else {
		m_pageSuccess = true;
		//writeResponse(new Response(false, message));
	}
}

void Connection::pageLoadingFromCommand() {
	m_pageLoadingFromCommand = true;
}

void Connection::pendingLoadFinished(bool success) {
	m_pageSuccess = success;
	if (m_commandWaiting)
		startCommand();

	if (m_pageLoadingFromCommand) {
		m_pageLoadingFromCommand = false;
		if (m_pendingResponse) {
			writeResponse(m_pendingResponse);
			m_pendingResponse = NULL;
		}
	}
}

void Connection::finishCommand(Response *response) {
	m_command->deleteLater();
	m_arguments.clear();
	m_commandName.clear();

	m_command = NULL;

	if (m_pageLoadingFromCommand)
		m_pendingResponse = response;
	else
		writeResponse(response);
}

void Connection::writeResponse(Response *response) {
	QByteArray messageUtf8;
	QString messageLength;

	if (response->isSuccess()) {
		m_socket->write("ok\n");
	} else {
		m_socket->write("failure\n");
	}

	messageUtf8 = response->message().toUtf8();
	messageLength = QString::number(messageUtf8.size()) + "\n";

	m_socket->write(messageLength.toAscii());
	m_socket->write(messageUtf8);

	delete response;
}

