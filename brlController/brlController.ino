
#include"servoHub.h"
#include"stepper.h"


void setup (){
	// ATTENTION: initialize servoHub BEFORE stepper
	// to set servos to neutral and prevent mechanical collision
	servoHub srv;
	stepper stp;
  
	stp.gotochar(0, first);
	srv.setOutside(0);
	stp.gotochar(0, second);
	srv.setInside(0);
	stp.gotochar(1, first);
	srv.setInside(0);
	stp.gotochar(1, second);
	srv.setOutside(0);
  stp.gotochar(2, first);
  delay(500);
  stp.gotochar(0, first);
  srv.setInside(0);
  stp.gotochar(0, second);
  srv.setOutside(0);
  stp.gotochar(1, first);
  srv.setOutside(0);
  stp.gotochar(1, second);
  srv.setInside(0);
  stp.gotochar(4,2);
}

void loop () {}
