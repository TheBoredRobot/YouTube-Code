#include <AccelStepper.h>

#define pul1 2
#define dir1 3

#define pul2 4
#define dir2 5

#define pul3 6
#define dir3 7

int speed1;
int speed2;
int speed3;

AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);
AccelStepper stepper3(1, pul3, dir3);

void setup() {
  stepper1.setMaxSpeed(500);
  stepper2.setMaxSpeed(500);
  stepper3.setMaxSpeed(500);

}

void loop() {
  speed1 = map(analogRead(A0), 0, 1023, -500, 500);
  stepper1.setSpeed(speed1);
  stepper1.runSpeed();

  speed2 = map(analogRead(A1), 0, 1023, -500, 500);
  stepper2.setSpeed(speed2);
  stepper2.runSpeed();

  speed3 = map(analogRead(A2), 0, 1023, -500, 500);
  stepper3.setSpeed(speed3);
  stepper3.runSpeed();

}
