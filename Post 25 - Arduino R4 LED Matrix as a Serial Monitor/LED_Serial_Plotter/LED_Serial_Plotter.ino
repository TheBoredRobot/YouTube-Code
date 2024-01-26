#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const int sensorPin = A0; // Analog pin where the sensor is connected
const int numColumns = 12; // Number of columns in the LED matrix

int sensorValues[numColumns]; // Array to store the history of sensor values

void setup() {
  Serial.begin(115200);
  matrix.begin();
  for (int i = 0; i < numColumns; i++) {
    sensorValues[i] = 0; // Initialize all elements to 0
  }
}

void loop() {
  // Shift the values in the array to the left
  for (int i = 0; i < numColumns - 1; i++) {
    sensorValues[i] = sensorValues[i + 1];
  }

  // Read the new sensor value and store it at the end of the array
  sensorValues[numColumns - 1] = analogRead(sensorPin);
  Serial.println(analogRead(sensorPin));

  // Map the sensor value to the LED matrix height
  int mappedValue = map(sensorValues[numColumns - 1], 0, 1023, 0, 8);

  // Clear the frame
  uint8_t frame[8][12] = {0};

  // Build the graph in the frame
  for (int x = 0; x < numColumns; ++x) {
    int height = map(sensorValues[x], 0, 1023, 0, 8);
    for (int y = 0; y < height; ++y) {
      frame[7 - y][x] = 1; // Light up LEDs to represent the sensor value
    }
  }

  // Render the frame
  matrix.renderBitmap(frame, 8, 12);

  delay(100); // Short delay for better visualization
}
