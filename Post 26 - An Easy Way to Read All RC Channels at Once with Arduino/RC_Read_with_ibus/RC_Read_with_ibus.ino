#include <IBusBM.h>   

IBusBM IBus;     //create IBus object:

//variables to store channel value:
int CH1 = 0; 
int CH2 = 0; 
int CH3 = 0; 
int CH4 = 0; 
int CH5 = 0; 
int CH6 = 0;


void setup() {
  Serial.begin(115200);
  IBus.begin(Serial); // iBUS connected to Serial0:
}


void loop() {
  CH1 = IBus.readChannel(0);
  CH2 = IBus.readChannel(1);
  CH3 = IBus.readChannel(2);
  CH4 = IBus.readChannel(3);
  CH5 = IBus.readChannel(4);
  CH6 = IBus.readChannel(5);
  
  Serial.print(CH1);
  Serial.print(", ");
  Serial.print(CH2);
  Serial.print(", ");
  Serial.print(CH3);
  Serial.print(", ");
  Serial.print(CH4);
  Serial.print(", ");
  Serial.print(CH5);
  Serial.print(", ");
  Serial.println(CH6);
}


  


 


