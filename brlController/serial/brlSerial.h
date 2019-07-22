#ifndef H_SERIAL_BRAILLE
#define H_SERIAL_BRAILLE

#include<string>

class brlSerial{
public:
	bool isConnected();
	void send(std::string s);
	std::string receive();
};

#endif