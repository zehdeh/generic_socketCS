#include "net/server/ServerSocket.h"
#include <sys/types.h>
#include <sys/socket.h>

ServerSocket::ServerSocket(const unsigned int port) : Socket() {
	bind(port);
	listen();
}

void ServerSocket::bind(const unsigned int port) {
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);

	int bind_return = ::bind(socketHandle, (struct sockaddr*)&addr, sizeof(addr));

	if(bind_return == -1) {
		throw SocketException("Could not bind socket.");
	}
}

void ServerSocket::listen() const {
	int listen_return = ::listen(socketHandle, MAXCONNECTIONS);

	if(listen_return == -1) {
		throw SocketException("Could not assign socket to listen.");
	}
}

void ServerSocket::accept(ServerSocket& newSocket) const {
	int addrLength = sizeof(addr);
	newSocket.socketHandle = ::accept(socketHandle, (sockaddr *)&addr, (socklen_t*) &addrLength);

	if(newSocket.socketHandle <= 0) {
		throw SocketException("Could not establish socket connection");
	}
}
