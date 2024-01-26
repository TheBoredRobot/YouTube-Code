#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  char sensorValueText[4];
  snprintf(sensorValueText, sizeof(sensorValueText), "%d", sensorValue);
  

  matrix.clear();
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(sensorValueText);
  matrix.endText();
  matrix.endDraw();
}