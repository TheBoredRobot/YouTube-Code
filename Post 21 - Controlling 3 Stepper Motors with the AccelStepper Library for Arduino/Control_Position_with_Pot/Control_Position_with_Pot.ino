#include <AccelStepper.h>

#define pul1 2
#define dir1 3

#define pul2 4
#define dir2 5

#define pul3 6
#define dir3 7

int position1;
int position2;
int position3;

AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);
AccelStepper stepper3(1, pul3, dir3);

void setup() {
  stepper1.setMaxSpeed(500);
  stepper2.setMaxSpeed(500);
  stepper3.setMaxSpeed(500);
  Serial.begin(9600);

}

void loop() {
  position1 = map(analogRead(A0), 0, 1023, 0, 200);
  stepper1.setSpeed(500);
  stepper1.moveTo(position1);
  stepper1.runSpeedToPosition();
  Serial.println(position1);

  position2 = map(analogRead(A1), 0, 1023, 0, 200);
  stepper2.setSpeed(500);
  stepper2.moveTo(position2);
  stepper2.runSpeedToPosition();

  position3 = map(analogRead(A2), 0, 1023, 0, 200);
  stepper3.setSpeed(500);
  stepper3.moveTo(position3);
  stepper3.runSpeedToPosition();

}
