#define DIR1 4
#define PWM1 5

#define encoderPinA 2
#define encoderPinB 3
volatile long encoderCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoder, RISING);
}

void loop() {
  digitalWrite(DIR1, LOW);
  analogWrite(PWM1, 50);  
  Serial.println(encoderCount);
}

void handleEncoder() {
  if (digitalRead(encoderPinA) > digitalRead(encoderPinB)){
    encoderCount++;
  }
  else{
    encoderCount--;
  }
}


