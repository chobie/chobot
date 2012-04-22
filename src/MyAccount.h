#include "common.h"
#include "skype-embedded_2.h"

class MyAccount : public Account
{
public:
	typedef DRef<MyAccount, Account> Ref;
	typedef DRefs<MyAccount, Account> Refs;

	bool loggedIn;
	bool loggedOut;

	MyAccount(unsigned int oid, SERootObject* root);
	void OnChange(int prop);

	void BlockWhileLoggingIn ();
	void BlockWhileLoggingOut ();
};
