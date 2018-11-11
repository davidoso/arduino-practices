/*
 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe
*/
#include <Stepper.h>

// Change this to fit the number of steps per revolution for your motor
const int stepsPerRevolution = 200;

// Initialize the stepper library on pins 1 through 4
Stepper myStepper(stepsPerRevolution, 1, 2, 3, 4);


void setup() {
  // Set the speed at 60 rpm
  myStepper.setSpeed(60);
  // Initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // Step one revolution in one direction
  Serial.println("Clockwise...");
  myStepper.step(stepsPerRevolution);
  delay(500);
  
  // Step one revolution in the other direction
  Serial.println("Counterclockwise...");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
