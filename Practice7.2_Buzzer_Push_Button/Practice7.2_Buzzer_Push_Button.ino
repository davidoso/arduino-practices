/*
  Buzzer and Push Button
  
Description:
  Buzzer keeps or stops beeping (tone) for a steady time
  until push button is pressed
  
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
  
Reference:
  http://mecabot-ula.org/tutoriales/arduino/practica-10-encender-un-led-con-boton-pulsador-y-luego-apagarlo-con-el-mismo-boton/
*/


int buzzer = 7;
int button = 2;
boolean lowState = true;
int v;
int toggle;

int val = 0;      // Stores read state
int state = 0;    // 0 led turned off. 1 led turned on
int old_val = 0;  // Stores current state that becomes old state


void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  val = digitalRead(button); // Read push button state
  
  if ( (val == HIGH) && (old_val == LOW) ) {
    state = 1 - state;
    delay(10); // Wait 10ms
  }
  old_val = val; // Save current state before loop starts again
  
  if (state == 1) {
   tone(buzzer, 1000); // Send 1KHz sound signal
  }
  else {
   noTone(buzzer); // Stop sound
  }
}
