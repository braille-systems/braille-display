#ifndef H_STEPPER_BRAILLE
#define H_STEPPER_BRAILLE

//http://techclub.su/article_arduino07

enum charHalf {
	first,
	second
};

class stepper {
	const int pinStep = 5; //D5
	const int pinDir = 4; //D4
	const int moveDelay = 3; //delay between steps in milliseconds
	const int StepModePinsCount = 3; //size of StepMode, StepModePins
	const int StepModePins[3] = {8, 7, 6}; //contacts responsible for stepper mode - MS1, MS2, MS3
	const bool StepMode[3] = {1, 1, 0}; // 1/4 of a step (000 - 1 step, 111 - 1/16 of a step)
	const int pinEndstop = 3;
	const int initPosOffset = 0; //offset in steps from place where endstop touches the bumper to initial position (zeroth character, first half)
	const int halfCharSteps = 0; //steps to move along half a character
	const int halfToFullChar = 0; // steps to move from first to second half
	int currChar; // number of current char
	charHalf currCharHalf; // number of current char half
	
	void rotate(int steps);
public:
	stepper();
	void gotochar (int nchar, charHalf half);
};

stepper::stepper (){
	//init stepper
	pinMode(pinStep, OUTPUT);
	pinMode(pinDir, OUTPUT);
	for(int i = 0; i < StepModePinsCount; i++)
		pinMode(StepModePins[i], OUTPUT);
	for(int i = 0; i < StepModePinsCount; i++)
		digitalWrite(StepModePins[i], StepMode[i] == 1 ? HIGH : LOW);
	//init endstop
	//calibrate: go to endstop
	//go to initial position
	rotate(-initPosOffset);
	currChar = 0;
	currCharHalf = 0;
}

void gotochar (int nchar, charHalf half){
	
}

void stepper::rotate(int steps){
	//TODO: if negative, change direction, then change sign
  for(int i = 0; i < steps; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(moveDelay);
    digitalWrite(pinStep, LOW);
    delay(moveDelay);
  }
}

#endif
