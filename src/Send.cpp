#include "Send.h"
#include "Command.h"
#include <iostream>
#include "skype-embedded_2.h"

#include "MySkype.h"

extern MySkype *skype;

Send::Send(QObject *parent) : Command(parent) {
}

void Send::start(QStringList &arguments) {
	SEStringList list;
	QStringList Arguments(arguments);
	QString blob, message;
	MyConversation::Refs inbox;
	MyConversation::Ref sconv;
	
	if (Arguments.size() != 2) {
		emit finished(new Response(false,"invalid arguments"));
		return;
	}

	blob    = Arguments[0];
	message = Arguments[1];

	//std::cout << "  room: " << (const char *)blob.toLocal8Bit()  << std::endl << "  message: " << (const char *)message.toLocal8Bit() << std::endl;

	skype->GetConversationList(inbox, Conversation::INBOX_CONVERSATIONS);
	fetch(inbox);

	for (int i = 0; i < inbox.size();i++) {
		SEString displayName;

		sconv = inbox[i];
		sconv->GetPropDisplayname(displayName);		
		
		if (strcmp((const char *)displayName,(const char *)blob.toLocal8Bit()) == 0) {
			//std::cout << (const char *)displayName << std::endl;

			Message::Ref rep;
			sconv->PostText((const char *)message.toLocal8Bit(), rep, false);
			
			emit finished(new Response(true,"ok"));
			return;
		}
	}
	
	emit finished(new Response(false,"not found"));
}
