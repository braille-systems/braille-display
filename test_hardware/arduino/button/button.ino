/*	BUTTON.INO: test any button or endstop
 *	built-in led lights up when button is pressed*/
 
const int pinButton = 3; //connect button and pull-down resistor
 
 void setup () {
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(pinButton, INPUT);
}
 
void loop () {
	if(digitalRead(pinButton)) digitalWrite(LED_BUILTIN, HIGH);
	else digitalWrite(LED_BUILTIN, LOW);
}
