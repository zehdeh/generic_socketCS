#ifndef SOCKET_HEADER
#define SOCKET_HEADER

#include <netinet/in.h>
#include <string>
#include <exception>

const int MAXRECV = 500;

class SocketException : public std::exception {
public:
	SocketException(const char* reason) : std::exception(), reason(reason) {}
	const char* what() const noexcept { return reason; }
private:
	const char* reason;
};

class Socket {
public:
	Socket();
	const Socket& operator<<(const int i) const { return operator<<(std::to_string(i)); }
	const Socket& operator<<(const std::string& s) const;
	const Socket& operator>>(std::string& s) const;
protected:
	bool isValid() const {
		return (socketHandle != -1);
	}
	sockaddr_in addr;
	int socketHandle;
};

#endif
