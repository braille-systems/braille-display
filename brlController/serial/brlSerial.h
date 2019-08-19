#ifndef H_SERIAL_BRAILLE
#define H_SERIAL_BRAILLE

#ifdef DEBUG_MODE
    #include<string>
	#ifndef String
			#define String std::string
    #endif //String
#endif //DEBUG_MODE

class brlSerial{
public:
	bool isConnected();
	void send(String s);
	String receive();
};

bool brlSerial::isConnected(){return false; /*TODO: implement*/}

void brlSerial::send(String s){/*TODO: implement*/}

String brlSerial::receive(){
	/*TODO: implement*/
	String res = "";
	return res;
}

#endif