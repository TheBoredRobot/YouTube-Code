/*
Controlling a Stepper Motor with a Remote Control and Arduino
 Brandon Tsuge
https://www.theboredrobot.com/post/controlling-a-stepper-motor-with-a-remote-control-and-arduino
In this example, I demonstrate how to use Arduino and remote control to control the speed of a stepper motor.

 */
//Define Pins
#define RCPin 2
#define DIR 4
#define STEP 5
#define MS3 6
#define MS2 7
#define MS1 8

//Set up time variables for Stepper motor
unsigned long previousMotorTime = millis();
long MotorInterval;
volatile long StartTime = 0;
volatile long CurrentTime = 0;

//Set up time variables for RC Read
volatile long Pulses = 0;
int PulseWidth = 0;


void setup() {
  Serial.begin(9600);

  //RC Read Setup
  pinMode(RCPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RCPin), PulseTimer, CHANGE); 

  // Set pins 4-8 to Outputs
  for (int i = 4; i <= 8; i++){
    pinMode(i, OUTPUT);
  }

  //Set MS1 to full step mode
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
}


void loop() {
  digitalWrite(STEP, LOW);

  //Only save HIGH pulse lengths
  if (Pulses < 2000){
    PulseWidth = Pulses;
  }

  //Stepper motor speed, bigger MotorInterval is a slower speed.
  if (PulseWidth >= 1400 && PulseWidth <= 1600){
    digitalWrite(STEP, LOW); //Motor doesn't move if the joystick is near the midpoint
  }
  else if (PulseWidth < 1400){
    digitalWrite(DIR, LOW);
    MotorInterval = map(PulseWidth, 1000, 1400, 1, 25); //map the RC signal to the motor speed in reverse when the joystick is pulled down
  }
  else if (PulseWidth > 1600){
    digitalWrite(DIR, HIGH);
    MotorInterval = map(PulseWidth, 1600, 1984, 25, 1); //map the RC signal to the motor speed when the joystick is pushed forward.
  }
  
  //check if the MotorInterval time has elapsed and step the motor.
  unsigned long currentMotorTime = millis(); 
  if (currentMotorTime - previousMotorTime > MotorInterval){
    digitalWrite(STEP, HIGH);
    previousMotorTime = currentMotorTime;
  }  
}

//Function to measure the length of the pulses from the remote control
void PulseTimer(){
  CurrentTime = micros();
  if (CurrentTime > StartTime){
    Pulses = CurrentTime - StartTime;
    StartTime = CurrentTime;
  }
}
