#include "MyAccount.h"

MyAccount::MyAccount(unsigned int oid, SERootObject* root) : Account(oid, root)
{
	loggedIn  = false;
	loggedOut = false;
};

void MyAccount::OnChange(int prop)
{
	if (prop == Account::P_STATUS){
		Account::STATUS loginStatus;
		this->GetPropStatus(loginStatus);
		if (loginStatus == Account::LOGGED_IN){
			loggedIn  = true;
		};
		if (loginStatus == Account::LOGGED_OUT) {
			loggedOut = true;
		};
	};

	if (prop == Account::P_LOGOUTREASON)
	{
		Account::LOGOUTREASON whyLogout;

		this->GetPropLogoutreason(whyLogout);
		if (whyLogout != Account::LOGOUT_CALLED)
		{
			printf("%s\n", (const char*)tostring(whyLogout));
		};
	};
};

void MyAccount::BlockWhileLoggingIn ()
{
	while ( (!this->loggedIn) && (!this->loggedOut) )
	{
		Delay(1);
	};

	if (!this->loggedIn)
	{
		printf("Login failed.\n");
	};
};

void MyAccount::BlockWhileLoggingOut ()
{
	while (!this->loggedOut) { Delay(1); };
};
