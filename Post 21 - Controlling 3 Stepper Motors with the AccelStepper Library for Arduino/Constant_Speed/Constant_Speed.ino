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
  stepper1.setSpeed(50);

  stepper2.setMaxSpeed(1000);
  stepper2.setSpeed(100);

  stepper3.setMaxSpeed(1000);
  stepper3.setSpeed(500);


}

void loop() {
  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();


}
