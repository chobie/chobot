#include "skype-embedded_2.h"
#include "MyAccount.h"
#include "MyConversation.h"

class MySkype : public Skype
{

public:
	Account*      newAccount(int oid);
	Conversation* newConversation(int oid);

	MyConversation::Refs inbox;
	void OnConversationListChange(const ConversationRef &conversation, const Conversation::LIST_TYPE &type, const bool &added);
};
