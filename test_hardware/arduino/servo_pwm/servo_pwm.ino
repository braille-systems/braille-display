/* written with the help of Adafruit PWM library example 'servo'
 * PCA9685 PWM 16-channel driver connected:
 * SDA->A4, SCL->A5 (though S4 is Arduino SDA, A5-SCL!) 
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

const int n = 6; //number of servos
int posInside[n] = {90, 90, 90, 95, 66, 46};  // "inside" positions
int steps[n] = {20, 31, 31, 43, 42, 32};  // movement from "inside" positions



Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

/*
 * angleToPulse(int ang)
 * gets angle in degree and returns the pulse width
 * also prints the value on seial monitor
 * written by Ahmad Nejrabi for Robojax, Robojax.com
 */
int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

void setInside(int srvNum) {
  pwm.setPWM(srvNum, 0, angleToPulse(posInside[srvNum]));
  unsigned long timingSer = millis();
  while(millis() - timingSer < 10)
    continue;
}

void setOutside(int srvNum) {
  pwm.setPWM(srvNum, 0, angleToPulse(posInside[srvNum]-steps[srvNum]));
  unsigned long timingSer = millis();
  while(millis() - timingSer < 10)
    continue;
}

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

}

void loop() {
  setInside(0); //control servo attached to 0-th position
  delay(1000);
  setOutside(0);
  delay(1000);

}
