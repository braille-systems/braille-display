#ifndef H_STEPPER_BRAILLE
#define H_STEPPER_BRAILLE

//http://techclub.su/article_arduino07

enum charHalf {
	first,
	second
};

class stepper {
	int nchars = 5; //number of characters in a display
	/*settings for 1/16 of step (ms1=0, ms2=1, ms3=1)*/
	const int pinStep = 5; //D5
	const int pinDir = 4; //D4
	const int moveDelay = 3; //delay between steps in milliseconds
	const int pinEndstop = 3;
	const int pinDisableStepper = 9; //D9
	const int maxCalibSteps = 1800; //stop if no endstop signal after maxCalibSteps
	const int calibPace = 1;
	
	int currChar; // number of current char
	charHalf currCharHalf; // number of current char half
	bool isBroken = false;
	
protected:
	int initPosOffset = 1630; //offset in steps from place where endstop touches the bumper to initial position (zeroth character, first half)
	int halfCharSteps = 70; //steps to move along half a character
	int halfToFullChar = 63; // steps to move from first to second half
	
	void rotate(int steps);
public:
	stepper();
	void gotochar (int nchar, charHalf half);
	bool broken(){return isBroken; }
};

stepper::stepper (){
	//init stepper
	pinMode(pinStep, OUTPUT);
  digitalWrite(pinDisableStepper, HIGH);
	pinMode(pinDir, OUTPUT);
	
	//init endstop
	pinMode(pinEndstop, INPUT);
	
	//calibrate: go to endstop
	int currSteps = 0;
	while(digitalRead(pinEndstop) == LOW){
		rotate(-calibPace);
		currSteps += calibPace;
		if(currSteps > maxCalibSteps){
			currChar = 0;
			currCharHalf = first;
			isBroken = true;
			return;
		}
	}
	//go to initial position
	rotate(initPosOffset);
	currChar = 0;
	currCharHalf = first;
}

void stepper::gotochar (int nchar, charHalf half){
	int steps = (nchar - currChar) * (halfCharSteps + halfToFullChar);
	if (half == second && currCharHalf == first) steps += halfToFullChar;
	if (half == first && currCharHalf == second) steps -= halfToFullChar;
	steps *= -1; //direction is opposite
	rotate(steps);
	currChar = nchar;
	currCharHalf = half;
}

void stepper::rotate(int steps){
	//if 'steps' negative, change direction
  if (steps < 0){
    digitalWrite(pinDir, LOW);
    steps = -steps; 
  } else {
    digitalWrite(pinDir, HIGH);
  }
  for(int i = 0; i < steps; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(moveDelay);
    digitalWrite(pinStep, LOW);
    delay(moveDelay);
  }
}

#endif
