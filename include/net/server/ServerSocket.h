#ifndef SERVERSOCKET_HEADER
#define SERVERSOCKET_HEADER

#include "socketCS/Socket.h"

const int MAXCONNECTIONS = 5;

class ServerSocket : public Socket {
public:
	ServerSocket() {}
	ServerSocket(const unsigned int port);
	void accept(ServerSocket& newSocket) const;
protected:
	void bind(const unsigned int port);
	void listen() const;
};

#endif
