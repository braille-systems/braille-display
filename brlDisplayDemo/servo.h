#ifndef H_SERVO_BRAILLE
#define H_SERVO_BRAILLE

/** see also: ../test_hardware/arduino/servo-pwm/ */
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define SERVOMIN  (125)
#define SERVOMAX  (575)

class Servo {
	Adafruit_PWMServoDriver pwm;
	static int angleToPulse(int ang);
	const int delayMillis = 10; //delay after every servo switch in switching function

	int angle;
	int pin; // from 0 to 15
public:
	Servo(int pinNum);
	void setAngle(int ang);
	int getAngle();
};

int Servo::angleToPulse(int ang){
	return map(ang, 0, 180, SERVOMIN, SERVOMAX);
}

void Servo::setAngle(int ang){
	pwm.setPWM(pin, 0, angleToPulse(ang));
	delay(delayMillis);
}

Servo::Servo (int pinNum): pin(pinNum) {
	pwm = Adafruit_PWMServoDriver();
	pwm.begin();
	pwm.setPWMFreq(60);
}

#endif // H_SERVO_BRAILLE
