#include "net/client/ClientSocket.h"
#include <arpa/inet.h>

ClientSocket::ClientSocket(const std::string host, const unsigned int port) : Socket() {
	connect(host, port);
}

void ClientSocket::connect(const std::string& host, const unsigned int port) {
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);

	int status = inet_pton(AF_INET, host.c_str(), &addr.sin_addr);
	status = ::connect(socketHandle, (sockaddr*)&addr, sizeof(addr));

	if(status != 0) throw SocketException("Could not connect.");
}
