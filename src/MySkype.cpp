#include "MySkype.h"

void MySkype::OnConversationListChange(
		const ConversationRef &conversation, 
		const Conversation::LIST_TYPE &type, 
		const bool &added)
	{

	// if conversation was added to inbox and was not in there already (just in case..) -> append to our own inbox list
	if ( (type == Conversation::INBOX_CONVERSATIONS) && (added) && (!inbox.contains(conversation)) )
	{
		inbox.append(conversation);
	};
};

Account* MySkype::newAccount(int oid){
	return new MyAccount(oid, this);
}
Conversation* MySkype::newConversation(int oid){
	return new MyConversation(oid, this);
}