//Define pin numbers for motors
#define DIR1 4
#define PWM1 5
#define DIR2 7
#define PWM2 6

//Define pin numbers for encoders
#define encoder1Pin 2
#define encoder2Pin 3

//Variables for encoder counts
volatile long encoder1Count = 0;
volatile long encoder2Count = 0;

//Variables for PID Control
long previousTime = 0;
float ePrevious = 0;
float eIntegral = 0;

void setup() {
  Serial.begin(9600);

  //Set pin modes
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(encoder1Pin, INPUT);
  pinMode(encoder2Pin, INPUT);
  
  //Interrupts for encoder pins
  attachInterrupt(digitalPinToInterrupt(encoder1Pin), handleEncoder1, RISING);
  attachInterrupt(digitalPinToInterrupt(encoder2Pin), handleEncoder2, RISING);
}

void loop() {
  //Set desired setpoint for motor 2  
  int target = encoder1Count;

  //Move motor 1
  digitalWrite(DIR1, 1);
  analogWrite(PWM1, 50);

  //PID gains and computation
  float kp = 2.0;
  float kd = 0.0;
  float ki = 0.0;
  float u = pidController(target, kp, kd, ki);

  //Control motor 2 based on PID
  moveMotor(DIR2, PWM2, u);

  //Print statements for debugging
  Serial.print(encoder1Count);
  Serial.print(", ");
  Serial.println(encoder2Count);

}

//Functions called during interrupts
void handleEncoder1() {
  encoder1Count++;
}
void handleEncoder2() {
  encoder2Count++;
}

void moveMotor(int dirPin, int pwmPin, float u){
  //Maximum motor speed
  float speed = fabs(u);
  if (speed > 255){
    speed = 255;
  }
  //Stop the motor during overshoot
  if (encoder2Count > encoder1Count){
    speed = 0;
  }
  //Control the motor
  int direction = 0;
  digitalWrite(dirPin, direction);
  analogWrite(pwmPin, speed);
}

float pidController(int target, float kp, float kd, float ki) {
  //Measure time elapsed since the last iteration
  long currentTime = micros();
  float deltaT = ((float)(currentTime - previousTime)) / 1.0e6;

  //Compute the error, derivative, and integral
  int e = target - encoder2Count;
  float eDerivative = (e - ePrevious) / deltaT;
  eIntegral = eIntegral + e * deltaT;
  
  //Compute the PID control signal
  float u = (kp * e) + (kd * eDerivative) + (ki * eIntegral);
  
  //Update variables for the next iteration
  previousTime = currentTime;
  ePrevious = e;

  return u;
}
