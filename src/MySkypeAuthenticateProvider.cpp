#include "MySkype.h"
#include "MySkypeAuthenticateProvider.h";
#include "keypair.h"

extern MySkype *skype;
SEString inetAddr   = "127.0.0.1";
uint portNum        = 8963;

bool MySkypeAuthenticateProvider::Login(SEString myAccountName, SEString myAccountPsw)
{
	printf("Creating skype ..\n");
	skype = new MySkype();

	printf("Submitting application token..\n");
	getKeyPair ();
	skype->init(keyBuf, inetAddr, portNum, "streamlog.txt");
	skype->start();

	printf("Retrieving account ..\n");
	MyAccount::Ref account;

	if (skype->GetAccount(myAccountName, account))
	{
		printf("Logging in..\n");
		account->LoginWithPassword(myAccountPsw, false, true);
		account->BlockWhileLoggingIn();

		if (account->loggedIn)
		{
				
			printf("Loggin complete.\n");

/*
			Conversation::Ref conv;
			SEStringList parterNames;
			parterNames.append("MelodyChat");
			skype->GetConversationList(skype->inbox, Conversation::INBOX_CONVERSATIONS);
			fetch(skype->inbox);

			for(int i = 0; i< skype->inbox.size(); i++){
				SEString displayName;
				skype->inbox[i]->GetPropIdentity(displayName);
				printf("Converation %s", (const char *)displayName);
			}
*/

//			if (skype->GetConversationByParticipants(parterNames,conv, true, false)) {
/*
			if (skype->GetConversationByBlob("Kgwqei9AwHMfe_GOY2l1Tz3xRVvzEqPURRZoiX8ImgM5Bg4hUYVSvjSVInx78tLfdsv2zPvUcETksqJiP3dqQQ2NdpQD",conv,false)){
				SEString displayName;
				conv->GetPropDisplayname(displayName);
				Message::Ref rep;
				conv->PostText("Hey, Whats up", rep, false);
				printf("Conversation displayName: %s\n", (const char*)displayName);
			}			
*/

			printf("Now accepting incoming chat messages.\n");
			return true;
		};
	}
	else
	{
		printf("Account does not exist\n");
		return false;
	};
}