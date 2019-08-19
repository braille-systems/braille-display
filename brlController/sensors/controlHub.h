#ifndef H_HUB_CONTROL
#define H_HUB_CONTROL

#ifdef DEBUG_MODE
    #include<string>
    #include<vector>
	#ifndef String
			#define String std::string;
    #endif //String
#else
    #include <ArduinoSTL.h>
#endif //DEBUG_MODE

#include"../speaker/pitches.h"
#include"button.h"
#include"joystick.h"

struct keysRefreshRes{
    bool soundMode;
    note::note_t toSpeaker;
    String toSerial;
};

class controlHub{
	std::vector<button> keys;
    button helpButton;
	button muteButton;
	joystick jStick;
public:
	void setKeyPins(std::vector<int>keyPins);
	void setHelpPin (int helpPin);
	void setMutePin (int mutePin);
	virtual ~controlHub(){/*TODO: free keys*/};
	keysRefreshRes refresh();
};

keysRefreshRes controlHub::refresh(){
    /*TODO: implement*/
    /**@usage call as frequently as possible to catch all user's input.
     * Normally there is no delay in this function*/
    keysRefreshRes res;
    res.toSerial = "";
    res.toSpeaker = note::none;
    res.soundMode = true; //sound on
    return res;
}

#endif
