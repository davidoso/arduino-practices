/*
  LM35 Temperature Sensor
  
Description:
  Turn on a specific led according to temperature changes.
  The LM35 is a common TO-92 temperature sensor.
  It is often used with the equation:
  temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;
  This does not yield high resolution, though
  
Author:
  created September 14, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=HW6IFt9DBMo
*/


byte tempPin = A0; // LM35 pin
float tempVal;

byte ledA = 7;
byte ledB = 5;
byte ledC = 3;


void setup() {
  for(int i=3;i<8;i+=2){
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(9600); // Set rate for serial data transmission in bits per second (baud)
}

void loop() {
  tempVal =  analogRead(tempPin) * 0.48828125;
  Serial.print("TEMPERATURE = ");
  Serial.print(tempVal);
  Serial.print("*C");
  Serial.println();
  
  if (tempVal < 28) {
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
  }
  else if (tempVal >= 28 && tempVal < 30) {
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
  }
  else {
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
  }
  
  delay(500);
}
