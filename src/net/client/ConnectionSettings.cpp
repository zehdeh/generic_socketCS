#include "net/generic/ConnectionSettings.h"
#include <iostream>

// Client-specific function to query data from keyboard input
void ConnectionSettings::clientIO() {
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
	std::cout << "1. aes_256_cbc" << std::endl;
	std::cout << "2. aes_256_ecb" << std::endl;
	std::cout << "3. aes_256_ofb" << std::endl;

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
