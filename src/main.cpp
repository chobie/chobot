#include <QtGui>
#include <QSettings>
#include <iostream>
#include <unistd.h>

#include "common.h"
#include "skype-embedded_2.h"
#include "MySkype.h"
#include "MySkypeAuthenticateProvider.h"

#include "Server.h"

using namespace Sid;

MySkype* skype;

int main(int argc, char **argv) {
	bool loginSuccessful;
	SEString myAccountName;
	SEString myAccountPsw;

	if (setpgid(0, 0) < 0) {
		std::cerr << "Unable to set new process group." << std::endl;
		return 1;
	}

	QApplication app(argc, argv);
	app.setApplicationName("chobot");
	app.setOrganizationName("chobie");
	app.setOrganizationDomain("chobie.org");
	
	QString path = app.applicationDirPath() + QDir::separator() + "chobot.ini";
	QSettings config(path, QSettings::IniFormat);
	QString account = config.value("user").toString();
	QString password = config.value("password").toString();
	
	myAccountName = account.toLocal8Bit();
	myAccountPsw = password.toLocal8Bit();
	
	loginSuccessful = MySkypeAuthenticateProvider::Login(myAccountName,myAccountPsw);
	if (loginSuccessful) {
		Server server(0);
		
		if (server.start()) {
			std::cout << "Skypekit server started, listening on port: " << server.serverPort() << std::endl;
			int res =  app.exec();

	/*
			printf("Logging out..\n");
			account->Logout(false);
			account->BlockWhileLoggingOut();
			printf("Logout complete.\n");
	*/
			return res;
		} else {
			std::cerr << "Couldn't start Skypekit server" << std::endl;
			return 1;
		}
	}
}
