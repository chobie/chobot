#include "skype-embedded_2.h"

class MyConversation : public Conversation
{
public:
	typedef DRef<MyConversation, Conversation> Ref;
	typedef DRefs<MyConversation, Conversation> Refs;
	MyConversation(unsigned int oid, SERootObject* root) : Conversation(oid, root) {};

	void OnMessage(const MessageRef & message);
};
