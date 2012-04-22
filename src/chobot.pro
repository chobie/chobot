TEMPATE = app
TARGET  = chobot
DESTDIR = .
HEADERS =  Server.h \
	Connection.h \
	Command.h \
	CommandFactory.h \
	CommandParser.h \
	Response.h \
	find_command.h \
	Send.h \
	MyAccount.h \
	MyConversation.h \
	MySkype.h \
	MySkypeAuthenticateProvider.h \
	common.h

SOURCES = main.cpp \
	Server.cpp \
	Connection.cpp \
	Command.cpp \
	CommandFactory.cpp \
	CommandParser.cpp \
	Response.cpp \
	Send.cpp \
	MyAccount.cpp \
	MyConversation.cpp \
	MySkype.cpp \
	MySkypeAuthenticateProvider.cpp \
	common.cpp

QT+= network
CONFIG += console
CONFIG -= app_bundle

QMAKE_INCDIR += ../../../../../interfaces/skype/cpp_embedded/src/platform/threading/pthread ../../../../../interfaces/skype/cpp_embedded/src/api ../../../../../interfaces/skype/cpp_embedded/src/ipc ../../../../../interfaces/skype/cpp_embedded/src/types ../../../../../interfaces/skype/cpp_embedded/src/platform/threading ../../../../../interfaces/skype/cpp_embedded/src/platform/transport ../../../../../interfaces/skype/cpp_embedded/src/platform/transport/tcp ../../../../../ipc/cpp ../../../../../ipc/cpp/platform/se ../../../../../ipc/cpp/ssl/cyassl/include ../../../../../ipc/cpp/ssl/cyassl/ctaocrypt/include ../../../../../ipc/cpp/ssl/cyassl/include/openssl ../../keypair

QMAKE_LIBDIR += ../../../../../interfaces/skype/cpp_embedded/build ../../../../../bin/linux-x86
QMAKE_LIBS += -lpthread -lskypekit-cppwrapper_2_lib -lskypekit-cyassl_lib
