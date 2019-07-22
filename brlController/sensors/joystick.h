#ifndef H_JOYSTICK_BRAILLE
#define H_JOYSTICK_BRAILLE

#include"button.h"

enum joystickState{
	jReleased,
	left,
	right,
	up,
	down
};

struct jRefreshRes{
	joystickState jState;
	buttonState jButtonState;
};

class joystick {
	button jButton;
	joystickState lastMeasuredState;
public:
	void attachPins (int jx, int jy, int jButtonPin);
	jRefreshRes refreshState();
};

#endif