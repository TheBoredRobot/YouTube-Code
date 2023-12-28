/*
Reading Values from an RC Receiver using Arduino
Brandon Tsuge

In this example, I demonstrate how to use Arduino to read RC (50Hz PWM) values using pulseIn() and external interrupts.
https://www.theboredrobot.com/post/reading-values-from-an-rc-receiver-using-arduino
 */

//define the pins and variables
#define RCPin 2
volatile long StartTime = 0;
volatile long CurrentTime = 0;
volatile long Pulses = 0;
int PulseWidth = 0;

void setup() {
  //set up the serial monitor, pin mode, and external interrupt.
  Serial.begin(9600);
  pinMode(RCPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RCPin),PulseTimer,CHANGE);
}

void loop() {
  //only save pulse lengths that are less than 2000 microseconds
  if (Pulses < 2000){
    PulseWidth = Pulses;
  }  
  Serial.println(PulseWidth);
}


void PulseTimer(){
  //measure the time between interrupts
  CurrentTime = micros();
  if (CurrentTime > StartTime){
    Pulses = CurrentTime - StartTime;
    StartTime = CurrentTime;
  }
}
