
#include"servoHub.h"
#include"stepper.h"


void setup (){
	// ATTENTION: initialize servoHub BEFORE stepper
	// to set servos to neutral and prevent mechanical collision
	servoHub srv;
	stepper stp;
	
	servoPos * srvPos = new servoPos[NSERVO];
	srvPos[2] = neutral; //yet unused
	
	stp.gotochar(0, first);
	srvPos[0] = outside;
	srvPos[1] = inside;
	srv.setPosition(srvPos);
	stp.gotochar(0, second);
	srvPos[0] = inside;
	srvPos[1] = outside;
	srv.setPosition(srvPos);
	stp.gotochar(1, first);
	srv.setPosition(srvPos);
	stp.gotochar(1, second);
	srvPos[0] = outside;
	srvPos[1] = inside;
	srv.setPosition(srvPos);
	stp.gotochar(2, first);
	delay(500);
	stp.gotochar(0, first);
	srvPos[0] = inside;
	srvPos[1] = outside;
	srv.setPosition(srvPos);
	stp.gotochar(0, second);
	srvPos[0] = outside;
	srvPos[1] = inside;
	srv.setPosition(srvPos);
	stp.gotochar(1, first);
	srv.setPosition(srvPos);
	stp.gotochar(1, second);
	srvPos[0] = inside;
	srvPos[1] = outside;
	srv.setPosition(srvPos);
	stp.gotochar(4,second);
	
	delete[](srvPos);
}

void loop () {}
