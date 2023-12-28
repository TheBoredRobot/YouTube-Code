#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  int sensorValue = analogRead(A0); // Read the sensor value
  int barHeight = map(sensorValue, 0, 1023, 0, 8); // Map the sensor value to the LED matrix height

  // Clear the frame
  uint8_t frame[8][12] = {0};

  // Build the bar graph in the frame
  for (int y = 0; y < barHeight; ++y) {
    for (int x = 0; x < 12; ++x) {
      frame[7 - y][x] = 1; // Light up LEDs to represent the sensor value
    }
  }

  // Render the frame
  matrix.renderBitmap(frame, 8, 12);

  delay(100); // Short delay for better visualization
}
