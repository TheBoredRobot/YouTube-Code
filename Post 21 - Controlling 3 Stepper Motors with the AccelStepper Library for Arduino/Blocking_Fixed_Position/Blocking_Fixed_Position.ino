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
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(100);

  stepper2.setMaxSpeed(200);
  stepper2.setAcceleration(100);

  stepper3.setMaxSpeed(200);
  stepper3.setAcceleration(100);

}

void loop() {
  stepper1.runToNewPosition(0);
  stepper1.runToNewPosition(200);
  stepper1.runToNewPosition(100);

  stepper2.runToNewPosition(0);
  stepper2.runToNewPosition(200);
  stepper2.runToNewPosition(100);
  
  stepper3.runToNewPosition(0);
  stepper3.runToNewPosition(200);
  stepper3.runToNewPosition(100);

}
