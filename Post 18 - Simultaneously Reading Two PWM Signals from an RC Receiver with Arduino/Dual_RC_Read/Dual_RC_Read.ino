/*
Simultaneously Reading Two PWM Signals from an RC Receiver with Arduino
 Brandon Tsuge
https://www.theboredrobot.com/post/simultaneously-reading-two-pwm-signals-from-an-rc-receiver-with-arduino
In this example, I demonstrate how to use Arduino to simultaneously read two RC (50Hz PWM) signals using external interrupts.

 */

//define the pins and variables
#define RCPinFWD 2
#define RCPinSide 3 

volatile long StartTimeFWD = 0;
volatile long CurrentTimeFWD = 0;
volatile long PulsesFWD = 0;
int PulseWidthFWD = 0;

volatile long StartTimeSide = 0;
volatile long CurrentTimeSide = 0;
volatile long PulsesSide = 0;
int PulseWidthSide = 0;

void setup() {
  //set up the serial monitor, pin mode, and external interrupt.
  Serial.begin(9600);
  pinMode(RCPinFWD, INPUT_PULLUP);
  pinMode(RCPinSide, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RCPinFWD),PulseTimerFWD,CHANGE);
  attachInterrupt(digitalPinToInterrupt(RCPinSide),PulseTimerSide,CHANGE);
}

void loop() {
  //only save pulse lengths that are less than 2000 microseconds
  if (PulsesFWD < 2000){
    PulseWidthFWD = PulsesFWD;
  } 
  if (PulsesSide < 2000){
    PulseWidthSide = PulsesSide;
  } 
  Serial.print(PulseWidthFWD);
  Serial.print("    ");
  Serial.println(PulseWidthSide);
}


void PulseTimerFWD(){
  //measure the time between interrupts
  CurrentTimeFWD = micros();
  if (CurrentTimeFWD > StartTimeFWD){
    PulsesFWD = CurrentTimeFWD - StartTimeFWD;
    StartTimeFWD = CurrentTimeFWD;
  }
}

void PulseTimerSide(){
  //measure the time between interrupts
  CurrentTimeSide = micros();
  if (CurrentTimeSide > StartTimeSide){
    PulsesSide = CurrentTimeSide - StartTimeSide;
    StartTimeSide = CurrentTimeSide;
  }
}
