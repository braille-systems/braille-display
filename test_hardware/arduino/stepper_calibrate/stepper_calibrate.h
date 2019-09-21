#ifndef H_STEPPER_CALIBRATE_BRAILLE
#define H_STEPPER_CALIBRATE_BRAILLE

/** To be used with stepper_calibrate.ino */

//Reason for using abs name: Arduino IDE has some limitations in its ability to work with paths
//proper relative way is "../../../brlController/stepper.h"
#include"C:/Users/user/dataVal/Work/braille3/brlController/stepper.h"

class stepperCalib : public stepper {
public:
	int getInitPosOffset(){return initPosOffset; }
	void addtoInitPosOffset(int value){
		gotochar(0, first);
		rotate(value - initPosOffset);
		initPosOffset += value;
	}
	int getHalfCharSteps(){return halfCharSteps; }
	void addtoHalfCharSteps(int value){
		gotochar(0, first);
		halfCharSteps += value;
	}
	int getHalfToFullChar(){return halfToFullChar; }
	void addtoHalfToFullChar(int value){
		gotochar(0, first);
		halfToFullChar += value; 
	}
};

#endif
