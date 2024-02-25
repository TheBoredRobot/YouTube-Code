volatile int pwmValueChannel1 = 0; // Variable to store PWM value from channel 1 (pin 2)
volatile int pwmValueChannel2 = 0; // Variable to store PWM value from channel 2 (pin 3)

unsigned long risingEdgeChannel1 = 0; // Timestamp of the rising edge on channel 1 (pin 2)
unsigned long risingEdgeChannel2 = 0; // Timestamp of the rising edge on channel 2 (pin 3)

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  pinMode(2, INPUT); // Set pin 2 (channel 1) as input
  pinMode(3, INPUT); // Set pin 3 (channel 2) as input

  // Attach interrupt on pin 2 (channel 1) for CHANGE (both RISING and FALLING)
  attachInterrupt(digitalPinToInterrupt(2), isrForChannel1, CHANGE);

  // Attach interrupt on pin 3 (channel 2) for CHANGE (both RISING and FALLING)
  attachInterrupt(digitalPinToInterrupt(3), isrForChannel2, CHANGE);
}

void loop() {


  // Print the PWM values for each channel
  Serial.print(pwmValueChannel1);
  Serial.print(", ");
  Serial.println(pwmValueChannel2);

  delay(100); // Delay a bit to make it more readable
}

void isrForChannel1() {
  if (digitalRead(2) == HIGH) { // Pin 2 is high, indicating the rising edge for channel 1
    risingEdgeChannel1 = micros(); // Record timestamp of rising edge
  } else { // Pin 2 is low, indicating the falling edge for channel 1
    pwmValueChannel1 = micros() - risingEdgeChannel1; // Calculate pulse width
  }
}

void isrForChannel2() {
  if (digitalRead(3) == HIGH) { // Pin 3 is high, indicating the rising edge for channel 2
    risingEdgeChannel2 = micros(); // Record timestamp of rising edge
  } else { // Pin 3 is low, indicating the falling edge for channel 2
    pwmValueChannel2 = micros() - risingEdgeChannel2; // Calculate pulse width
  }
}
