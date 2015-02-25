#include "net/generic/ConnectionSettings.h"
#include "net/server/ServerSocket.h"

#include <iostream>

void ConnectionSettings::serverIO(ServerSocket& socket) {
	std::string buffer;
	socket >> buffer;
	int asciNo = atoi(buffer.c_str());
	mode = asciNo;

	socket >> buffer;
	cipherNo = atoi(buffer.c_str());

	socket >> buffer;
	text = buffer;
}
