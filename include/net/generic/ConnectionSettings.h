#ifndef CONNECTIONSETTINGS_HEADER
#define CONNECTIONSETTINGS_HEADER

#include <cstring>
class ServerSocket;

class ConnectionSettings {
public:
	void serverIO(ServerSocket& socket);
	void clientIO();
	char getMode() { return mode; }
	unsigned int getCipherNo() { return cipherNo; }
	std::string getText() { return text; }
private:
	char mode;
	unsigned int cipherNo;
	std::string text;
};

#endif
