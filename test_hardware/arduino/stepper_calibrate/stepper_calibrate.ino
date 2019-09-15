#include"stepper_calibrate.h"
/* interface:
 * g[i][j] - go to letter [i] (1 to 5) half [j] (1 to 2)
 * i+[value] - init position += [value], go to init pos
 * i-[value]
 * h1+[number] - halfCharSteps + number
 * h1-[number] - halfCharSteps - number
 * h2+[number] - halfToFullChar + number
 * h2-[number] - halfToFullChar - number
 * p - print initPos, halfCharSteps, halfToFullChar
 * */
const int minCommandLength = 3;

void setup (){
	Serial.begin(9600);
	stepper s;
	Serial.println("Arduino is ready to work.");
	while(true){
		if (Serial.available()) {
			String request = Serial.readString();
			if (request.length() < minCommandLength) request = "!errorRequest";
      int nLetter;
      charHalf halfLetter;
			switch((int)request[0]){
			case 'g':
				nLetter = (int)request[1];
				halfLetter = (request[2] == '1') ? first : second;
				s.gotochar(nLetter, halfLetter);
				break;
			case 'i':
				break;
			case 'h':
				break;
			case 'p':
				Serial.println("initPosOffset="+String(s.getInitPosOffset()));
				Serial.println("halfCharSteps="+String(s.getHalfCharSteps()));
				Serial.println("halfToFullChar="+String(s.getHalfToFullChar()));
				break;
			default:
				Serial.println("unknown command - no command starting with " + request.substring(0,1));
			}
		}
	}
}

void loop () {}
