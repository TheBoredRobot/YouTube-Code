void setup() {
  Serial.begin(115200);
}

void loop() {
  float time = micros() / 1e6;
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1);
  delay(100);

  Serial.print(time);
  Serial.print(", ");
  Serial.print(sensorValue1);
  Serial.print(", ");
  Serial.println(sensorValue2);

}
