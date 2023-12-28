//Define Pins for Motor 1
#define Motor1_stp 2 //Logic input: transition from LOW to HIGH to move one step
#define Motor1_dir 3 //Direction
#define Motor1_MS1 4 //MS1 and MS2 are logic pins from step size
#define Motor1_MS2 5 //https://learn.sparkfun.com/tutorials/easy-driver-hook-up-guide?_ga=2.13257203.554998849.1612426132-1952729559.1604906281 for truth table
#define Motor1_EN  6 
#define Motor2_stp 7 
#define Motor2_dir 8 
#define Motor2_MS1 9 
#define Motor2_MS2 10 
#define Motor2_EN  11


void setup() {
  //Set all motor pins to outputs
  pinMode(Motor1_stp, OUTPUT);
  pinMode(Motor1_dir, OUTPUT);
  pinMode(Motor1_MS1, OUTPUT);
  pinMode(Motor1_MS2, OUTPUT);
  pinMode(Motor1_EN, OUTPUT);
  pinMode(Motor2_stp, OUTPUT);
  pinMode(Motor2_dir, OUTPUT);
  pinMode(Motor2_MS1, OUTPUT);
  pinMode(Motor2_MS2, OUTPUT);
  pinMode(Motor2_EN, OUTPUT);
  
  //Write initial values to motor pins
  digitalWrite(Motor1_dir, LOW); //set the direction for motor 1
  digitalWrite(Motor1_MS1, LOW); //step size for motor 1
  digitalWrite(Motor1_MS2, LOW);
  digitalWrite(Motor1_EN, LOW); //enable motor 2
  digitalWrite(Motor2_dir, LOW); //set the direction for motor 2
  digitalWrite(Motor2_MS1, LOW); //step size for motor 2
  digitalWrite(Motor2_MS2, LOW);
  digitalWrite(Motor2_EN, LOW); //enable motor 2


}

void loop() {
  digitalWrite(Motor1_stp, LOW);
  delay(1);
  digitalWrite(Motor1_stp,HIGH);
  delay(1);
  digitalWrite(Motor2_stp, LOW);
  delay(1);
  digitalWrite(Motor2_stp,HIGH);
  delay(1);



}
