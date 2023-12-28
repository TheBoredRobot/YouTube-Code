#include <AccelStepper.h>

#define pul1 2
#define dir1 3

#define pul2 4
#define dir2 5

#define pul3 6
#define dir3 7

AccelStepper stepper1(1, pul1, dir1);
AccelStepper stepper2(1, pul2, dir2);
AccelStepper stepper3(1, pul3, dir3);

void setup() {
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
  stepper3.setMaxSpeed(1000);


}

void loop() {
  stepper1.setSpeed(750);
  stepper1.moveTo(400);
  stepper1.runSpeedToPosition();

  stepper2.setSpeed(100);
  stepper2.moveTo(200);
  stepper2.runSpeedToPosition();

  stepper3.setSpeed(50);
  stepper3.moveTo(600);
  stepper3.runSpeedToPosition();


}
