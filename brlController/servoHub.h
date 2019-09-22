#ifndef H_SERVO_HUB_BRAILLE
#define H_SERVO_HUB_BRAILLE

/** further information: ../test_hardware/arduino/servo-pwm/ */
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define SERVOMIN  (125)
#define SERVOMAX  (575)
#define NSERVO (3)

class servoHub {
	Adafruit_PWMServoDriver pwm;
	const int delayMillis = 10; //delay after every servo switch in switching function
	const int shiftDelayMillis = 500; //delay between moves
	int angInside[NSERVO] = {0, 180, 0};
	int angOut[NSERVO] = {180, 0, 180};
	int angNeutral[NSERVO] = {70, 50, 70};
	bool isBroken;
	
	int angleToPulse(int ang);
	void setAngle(int srv, int ang);
	
public:
	servoHub();
	void setInside(int srv);
	void setOutside(int srv);
	bool hubIsBroken(){return isBroken; };
};

servoHub::servoHub () {
	pwm = Adafruit_PWMServoDriver();
	pwm.begin();
	pwm.setPWMFreq(60);
	isBroken = false;
	for (int i = 0; i < NSERVO; i++) setAngle(i, angNeutral[i]);
}

int servoHub::angleToPulse(int ang){
	return map(ang,0, 180, SERVOMIN,SERVOMAX);
}

void servoHub::setAngle(int srv, int ang){
	if (srv < 0 || srv > NSERVO){ //out of bounds
		isBroken = true; //something went wrong
		return;
	}
	pwm.setPWM(srv, 0, angleToPulse(ang));
	delay(delayMillis);
}

void servoHub::setInside(int srv){
		setAngle(srv, angInside[srv]);
		delay(shiftDelayMillis);
		setAngle(srv, angNeutral[srv]);
		delay(shiftDelayMillis);
}

void servoHub::setOutside(int srv){
		setAngle(srv, angOut[srv]);
		delay(shiftDelayMillis);
		setAngle(srv, angNeutral[srv]);
		delay(shiftDelayMillis);
}

#endif
