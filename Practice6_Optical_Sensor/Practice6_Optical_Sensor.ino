/*
  CNY70
  
Description:
  The CNY70 is a reflective sensor that includes an infrared emitter
  and phototransistor in a leaded package which blocks visible light.
  If it detects a white or a dark surface turns either ledA or ledB.
  This is very useful to make Line Follower Robots
  
Author:
  created September 21, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=mCtQ-Mu3EsY
*/


int ledPinA = 7;    // White
int ledPinB = 5;    // Black
int infraPin = 1;   // LDR pin
int valorInfra = 0; // Initial value of sample


void setup() {
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinB, OUTPUT);
  pinMode(infraPin, INPUT);
}

void loop() {
  // Sample sensor
  valorInfra = digitalRead(infraPin);
  // If 0 is read, led will be turned off. If 1, led will turn on
  digitalWrite(ledPinA, valorInfra);
  // Reverse input and turn on/off the other led
  valorInfra = !valorInfra;
  digitalWrite(ledPinB, valorInfra);
}
