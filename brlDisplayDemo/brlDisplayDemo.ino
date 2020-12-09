#include "servo.h"

void setup() {
	Servo srv(0);
	int n_positions = 8;
	int * positions [n_positions];
	for (int i = 0; i < n_positions; i++){
		positions[i] = 180 * i / (n_positions - 1);
	}
	while(true){
		for (int i = 0; i < n_positions; i++){
			srv.setAngle(positions[i]);
			delay(1000);
		}
		delay(1000);
		for (int i = n_positions - 1; i >= 0; i--){
			srv.setAngle(positions[i]);
			delay(1000);
		}
		delay(2000);
	}
}

void loop() {}
