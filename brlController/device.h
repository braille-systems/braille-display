#ifndef H_DEVICE_BRAILLE
#define H_DEVICE_BRAILLE

#include "brailleDisplay/brailleDisplay.h"
#include"sensors/controlHub.h"
#include"serial/brlSerial.h"
#include"speaker/speaker.h"

class device{
public:
	brlSerial ser;
	controlHub ctrl;
	brailleDisplay brlDisp;
	speaker sound;
	void processSerInput();
};

#endif
