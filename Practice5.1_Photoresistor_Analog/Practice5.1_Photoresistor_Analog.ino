/*
  Photoresistor or LDR Sensor as ANALOG INPUT
  
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


const int LEDBui = 13;
const int LEDPin = 50;
const int LDRPin = A0;
const int threshold = 200;

void setup() {
  pinMode(LEDPin, OUTPUT);
  pinMode(LEDBui, OUTPUT);
  pinMode(LDRPin, INPUT);
}

void loop() {
  int input = analogRead(LDRPin);
  if (input > threshold) {
    digitalWrite(LEDPin, HIGH);
    digitalWrite(LEDBui, HIGH);
  }
  else {
    digitalWrite(LEDPin, LOW);
    digitalWrite(LEDBui, LOW);
  }
}
