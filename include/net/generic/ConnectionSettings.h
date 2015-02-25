#ifndef CONNECTIONSETTINGS_HEADER
#define CONNECTIONSETTINGS_HEADER

#include <cstring>

class ServerSocket;

class ConnectionSettings {
public:
	void serverIO(ServerSocket& socket) {
		std::string buffer;
		acceptSocket >> buffer;
		mode = buffer[0];

		acceptSocket >> buffer;
		cipherNo = atoi(buffer.c_str());
		std::cout << msg1 << std::endl;
	}
	void clientIO() {
		std::string inputBuffer;
		while(true) {
			std::cout << "Please choose encryption or decryption: (Type e or d and press enter)" << std::endl;
			getline(std::cin, inputBuffer);

			mode = inputBuffer[0];
			if(mode == 'e' || mode == 'd') {
				break;
			} else {
				std::cout << "Input not recognized!" << std::endl;
			}
		}
		std::cout << "Pick a cipher: (Type number and press enter)" << std::endl;
		std::cout << "1. AES" << std::endl;
		std::cout << "2. BF" << std::endl;
		std::cout << "3. DES" << std::endl;

		mode = 'e';
		while(true) {
			getline(std::cin, inputBuffer);
			cipherNo = inputBuffer[0] - '0';
			if(cipherNo >= 1 && cipherNo <= 3) {
				break;
			} else {
				std::cout << "Input not recognized! Repeat:" << std::endl;
			}
		}

		if(mode == 'e') {
			std::cout << "Enter your plaintext" << std::endl;
		} else {
			std::cout << "Enter your encrypted text" << std::endl;
		}

		getline(std::cin,text);

	}
	char getMode() { return mode; }
	unsigned int getCipherNo() { return cipherNo; }
	std::string getText() { return text; }
private:
	char mode;
	unsigned int cipherNo;
	std::string text;
};

#endif
