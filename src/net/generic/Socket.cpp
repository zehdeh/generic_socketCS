#include "net/generic/Socket.h"
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <sys/socket.h>

Socket::Socket() : socketHandle(-1){
	memset(&addr, 0, sizeof(addr));

	// Initialize Socket
	socketHandle = socket(AF_INET, SOCK_STREAM, 0);
	if(!isValid()) {
		throw SocketException("Could not create socket.");
	}

	int on = 1;
	if(setsockopt(socketHandle, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on)) != 0) {
		throw SocketException("Could not set options for socket.");
	}
}

// We introduce a kind of protocol here - messageLength followed by message.
// This allows us to send data of arbitrary length, e.g. strings
const Socket& Socket::operator<<(const std::string& s) const {
	uint32_t dataLength = htonl(s.length());
	int status = ::send(socketHandle, &dataLength, sizeof(uint32_t), MSG_CONFIRM);
	if(status == -1) {
		throw SocketException("Could not send data.");
	}
	status = ::send(socketHandle, s.c_str(), s.size(), MSG_CONFIRM);
	if(status == -1) {
		throw SocketException("Could not send data.");
	}

	return *this;
}

// Do two calls to recv to put back together the data
const Socket& Socket::operator>>(std::string& s) const {
	uint32_t dataLength;
	int receivedBytes = 0;

	// First call to get message length
	receivedBytes = recv(socketHandle, &dataLength, sizeof(uint32_t), 0);
	dataLength = ntohl(dataLength);

	std::vector<uint8_t> rcvBuf;
	rcvBuf.resize(dataLength, 0x00);

	// Second call to get actual data
	recv(socketHandle, &(rcvBuf[0]), dataLength, 0);

	s.assign(rcvBuf.begin(), rcvBuf.end());
}
