#ifndef H_BUTTON_BRAILLE
#define H_BUTTON_BRAILLE

enum buttonState{
	detached,
	untouched,
	pressed,
	released,
};

class button{
	int pin;
	buttonState state;
public:
	button():state(detached){};
	buttonState refreshState();
	void resetState();
	void attachPin(int pin);
};

#endif
