const int channelPins[6] = {2, 3, 4, 5, 6, 7}; // Pins connected to channels 1 through 6
unsigned long startMicros[6]; // Timestamps when a HIGH signal starts
unsigned long pwmValues[6]; // To store PWM values for each channel
bool currentStates[6]; // Current state (HIGH or LOW) of each channel

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(channelPins[i], INPUT);
    currentStates[i] = false;
  }
}

void loop() {
  for (int i = 0; i < 6; i++) {
    bool newState = digitalRead(channelPins[i]);
    if (newState != currentStates[i]) { // State change detected
      if (newState == HIGH) { // Rising edge
        startMicros[i] = micros();
      } else { // Falling edge
        pwmValues[i] = micros() - startMicros[i];
      }
      currentStates[i] = newState;
    }
  }

  // Print the PWM values every 100 milliseconds
  static unsigned long lastPrintTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - lastPrintTime >= 100) { // 100 ms has passed
    lastPrintTime = currentTime;
    for (int i = 0; i < 6; i++) {
      Serial.print(pwmValues[i]);
      if (i < 5) {
        Serial.print(", "); // Separate values with a comma and space
      } else {
        Serial.println(); // New line after the last value
      }
    }
  }
}
