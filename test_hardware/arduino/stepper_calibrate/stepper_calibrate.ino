#include"stepper_calibrate.h"
/* interface:
 * g[i][j] - go to letter [i] (0 to 4) half [j] (1 to 2)
 * i+[value] - init position += [value], go to init pos
 * i-[value]
 * h1+[number] - halfCharSteps + number
 * h1-[number] - halfCharSteps - number
 * h2+[number] - halfToFullChar + number
 * h2-[number] - halfToFullChar - number
 * print - print initPos, halfCharSteps, halfToFullChar
 * */
const int minCommandLength = 3;

void setup (){
	Serial.begin(9600);
	stepperCalib s;
	Serial.println("Arduino is ready to work.");
	while(true){
		if (Serial.available()) { //parse command from Serial
			String request = Serial.readString();
			if (request.length() < minCommandLength) request = "!errorRequest";
			int nLetter, value;
			charHalf halfLetter;
			switch((int)request[0]){
			case 'g':
				nLetter = (int)(request[1] - '0');
				halfLetter = (request[2] == '1') ? first : second;
				s.gotochar(nLetter, halfLetter);
        Serial.println("Gotochar: char " + String(nLetter) + ", half " + String(request[2]));
				break;
			case 'i':
				value = (int)(request[2] - '0');
				if (request[1] == '-') value *= -1;
				s.addtoInitPosOffset(value);
				Serial.println("initPosOffset: added " + String(value));
				break;
			case 'h':
				if (request.length() < 4){
					Serial.println("err: command with 'h' must contain 4 chars, but 3 given");
					break;
				}
				value = (int)(request[3] - '0');
				if (request[2] == '-') value *= -1;
				if (request[1] == '1') {
					s.addtoHalfCharSteps(value);
					Serial.println("halfCharSteps: added " + String(request[2]));
				} else {
					s.addtoHalfToFullChar(value);
					Serial.println("halfCToFullChar: added " + String(request[2]));
				}
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
