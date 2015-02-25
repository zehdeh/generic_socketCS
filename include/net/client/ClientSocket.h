#ifndef CLIENTSOCKET_HEADER
#define CLIENTSOCKET_HEADER

#include "net/generic/Socket.h"

class ClientSocket : public Socket {
public:
	ClientSocket(const std::string host, const unsigned int port);
	virtual ~ClientSocket() {}
protected:
	void connect(const std::string& host, const unsigned int port);
};

#endif

