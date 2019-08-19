/*	MAIN.CPP - main file of Braille Trainer controller in debug mode
	This file is only for debug mode and to be used with CMakeLists.txt
	in your favorite c++ environment that supports CMake.
	To compile a working program for Arduino board, open brlController.ino
	in Arduino IDE
*/

#define DEBUG_MODE (1);
#include<main.h>

int main(void){
	//Arduino imitation
    setup();
    int debug_iters = 50;
    for(int i=0; i< debug_iters; i++) loop();
}

