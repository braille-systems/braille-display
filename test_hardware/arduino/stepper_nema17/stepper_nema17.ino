
//http://techclub.su/article_arduino07

const int pinStep = 5;
const int pinDir = 4;
const int move_delay = 3; //delay between steps in milliseconds
const int steps_rotate_360 = 200; //steps per one revolution

const int StepModePinsCount = 3; //size of StepMode, StepModePins
const int StepModePins[3] = {8, 7, 6}; //contacts responsible for stepper mode - MS1, MS2, MS3
const bool StepMode[3] = {1, 1, 0}; // 1/4 of a step (000 - 1 step, 111 - 1/16 of a step)

void setup()
{
  pinMode(pinStep, OUTPUT);
  pinMode(pinDir, OUTPUT);

  for(int i = 0; i < StepModePinsCount; i++)
    pinMode(StepModePins[i], OUTPUT);

  //set stepper mode
  for(int i = 0; i < StepModePinsCount; i++)
    digitalWrite(StepModePins[i], StepMode[i] == 1 ? HIGH : LOW);
}


void loop(){
  digitalWrite(pinDir, HIGH); //forward direction
  rotate(steps_rotate_360);
  delay(move_delay*10);
  digitalWrite(pinDir, LOW); //backward direction
  rotate(steps_rotate_360);
  delay(move_delay*10);
}

void rotate(int steps){
  for(int i = 0; i < steps; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(move_delay);
    digitalWrite(pinStep, LOW);
    delay(move_delay);
  }
}
