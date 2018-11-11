/*
  Buzzer and Roller Lever
  
Description:
  The roller switch is similar to a button.
  Push to turn on and make buzzer ring,
  and release to turn off and mute buzzer
  
Author:
  created September 26, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=FQqm_2D_QTk
*/


int buzzer = 7;
int roller = 4;
int v;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(roller, INPUT);
}

void loop() {
  v = digitalRead(roller); // Read roller lever state
  if(v == HIGH)
    tone(buzzer, 1000); // Send 1KHz sound signal
  else
    noTone(buzzer); // Stop sound
}
