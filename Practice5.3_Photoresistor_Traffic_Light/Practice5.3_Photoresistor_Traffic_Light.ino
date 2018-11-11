/*
  Photoresistor or LDR Sensor
  
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
  
Video evidence:
  https://www.youtube.com/watch?v=7L4GdvHq8eA
*/


// This way of calibration is deprecated
//const long A = 1000;     //Resistencia en oscuridad en KΩ
//const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
//const int Rc = 10;       //Resistencia calibración en KΩ
const int LDRPin = A0;   //LDR pin

byte ledA = 50;
byte ledB = 51;
byte ledC = 52;
int light;


void setup()
{
   Serial.begin(9600); // Set rate for serial data transmission in bits per second (baud)
   pinMode(ledA, OUTPUT);
   pinMode(ledB, OUTPUT);
   pinMode(ledC, OUTPUT);
}

void loop()
{
   //light = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0
   //light = ((long)V*A*10)/((long)B*Rc*(1024-V));  //usar si LDR entre A0 y Vcc (como en el esquema anterior)
   
  /*
   *  Read an analog voltage value from the LDR (LDRPin), ranging from 0 to 1023.
   *  The map() function matches this range to one from 100 to 1000.
   *  The latter boundaries will be used to choose which led turn on
   */
  light = map(analogRead(LDRPin), 0, 1023, 0, 127);
  
  Serial.print("BRIGHTNESS = ");
  Serial.println(light);
  
  if (light < 30) {
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
  }
  else if (light < 70) {
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
