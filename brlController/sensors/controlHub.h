#ifndef H_HUB_CONTROL
#define H_HUB_CONTROL

#include<string>
#include<vector>
#include<speaker/pitches.h>
#include"button.h"
#include"joystick.h"

struct keysRefreshRes{
    bool soundMode;
    note::note_t toSpeaker;
    std::string toSerial;
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

#endif
