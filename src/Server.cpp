#include "Server.h"
#include "Connection.h"

#include <QTcpServer>

Server::Server(QObject *parent) : QObject(parent) {
	m_tcp_server = new QTcpServer(this);
}

bool Server::start() {
	connect(m_tcp_server, SIGNAL(newConnection()), this, SLOT(handleConnection()));
	return m_tcp_server->listen(QHostAddress::LocalHost, 8888);
}

quint16 Server::serverPort() const {
	return m_tcp_server->serverPort();
}

void Server::handleConnection() {
	QTcpSocket *socket = m_tcp_server->nextPendingConnection();
	new Connection(socket);
}
