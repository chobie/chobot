#include "MyConversation.h"

void MyConversation::OnMessage(const MessageRef & message)
{
/*
  Message::TYPE messageType;
  message->GetPropType(messageType);

  if (messageType == Message::POSTED_TEXT)
  {
    SEIntList propIds;
    SEIntDict propValues;
    propIds.append(Message::P_AUTHOR);
    propIds.append(Message::P_BODY_XML);
    propValues = message->GetProps(propIds);

		Sid::String str;
		Conversation::Ref conv;
		message->GetPropConvoId(conv);
		conv->GetPropDisplayname(str);

    if (propValues[0] != myAccountName)
    {
      printf("%s %s : %s\n",
			(const char*)str,
      (const char*)propValues[0],   // P_AUTHOR
      (const char*)propValues[1]);  // P_BODY_XML

      Message::Ref reply;
      this->PostText("This is an automated reply.", reply, false);
    };
  };
*/
};
