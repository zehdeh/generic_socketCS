#include "net/generic/ConnectionSettings.h"

void ConnectionSettings::serverIO(ServerSocket& socket) {
	std::string buffer;
	socket >> buffer;
	mode = buffer[0];

	socket >> buffer;
	cipherNo = atoi(buffer.c_str());

	socket >> buffer;
	text = buffer;
}
