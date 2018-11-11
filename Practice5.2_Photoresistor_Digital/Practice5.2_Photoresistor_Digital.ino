/*
  Photoresistor or LDR Sensor as DIGITAL INPUT
  
Description:
  Turn on a specific led according to light changes.
  The resistance of a photoresistor decreases
  with increasing incident light
  
Author:
  created September 19, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
*/


const int LEDPin = 50;
const int LDRPin = 2;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(LDRPin, INPUT);
}

void loop() {
  int value = digitalRead(LDRPin);
  if (value == HIGH) {
    digitalWrite(LEDPin, HIGH);
    delay(50);
    digitalWrite(LEDPin, LOW);
    delay(50);
  }
}
