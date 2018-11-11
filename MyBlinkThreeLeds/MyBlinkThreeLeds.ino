/*
  Blink using 3 LEDs
  
Description:
  Turns three LEDs on for half, one and two seconds, then off for one second, repeatedly
  
Author:
  created August 29, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
*/


byte led7 = 7;
byte led6 = 6;
byte led5 = 5;
byte potPin = 0; // Potentiometer pin
int delayTime = 500; // Default delay for LEDs

void setup() {
  pinMode(led7, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led5, OUTPUT);
}

void turnLED(byte led) {
  digitalWrite(led, HIGH);   // Turn the selected LED on (HIGH is the voltage level)
  delay(delayTime);          // Wait the amount of time returned by the potentiometer
  digitalWrite(led, LOW);
  delay(delayTime);
}

void loop() {
  delayTime = analogRead(potPin);
  turnLED(led7);
  turnLED(led6);
  turnLED(led5);
}
