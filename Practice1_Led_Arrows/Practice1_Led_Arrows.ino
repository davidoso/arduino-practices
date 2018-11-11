/*
  Arrows and Turn Signal using LEDs
  
Description:
  There are 10 LEDs arranged in a hexagon wider at the top and at the bottom
  on the breadboard. The LEDs blink in a fixed sequence forming a square tilted
  45 degrees (also, diamond) in the middle, two left arrows and two right arrows.
  A potentiometer may be used to adjust the speed the LEDs blink
  
Author:
  created September 06, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=BtvSyllYaMo
*/


/*
 *  The following array represent each vertex of the inner square.
 *  Each index depicts a LED blinking counterclockwise. Index 0 is the top LED.
 *  They turn on and off at different times
 */
byte ledSquare[] = { 7, 6, 5, 4 };

/*
 * These two pins are the outer arrows. Each one has 3 LEDs attached.
 * All the LEDs blink at the same time, so only one output pin is needed
 */
byte ledLeftArrow = 3;
byte ledRightArrow = 2;

// The potentiometer pin that reads its analog value
byte potPin = 0;
// The potentiometer returns an analog value between 0 and 1023
int potValue = 0;
// Default delay for leds in milliseconds
int delayTime = 500;


/*
 * 6 (instead of 10) pins are set as output because of the arrow arrays
 */
void setup() {
  for(int i=2;i<8;i++){
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(9600); // Set rate for serial data transmission in bits per second (baud)
}

// The next two methods turn on and off three leds for either left or right arrow
void turnONinnerArrow(byte led1, byte led2, byte led3) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}

void turnOFFinnerArrow(byte led1, byte led2, byte led3) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void loop() {
  /*
   *  Read an analog voltage value from the potentiometer (potPin), ranging from 0 to 1023.
   *  The map() function matches this range to one from 100 to 1000.
   *  The latter boundaries will be used to control the LEDs blinking speed
   */
  delayTime = map(analogRead(potPin), 0, 1023, 100, 1000);
  
  // Print a value from 100 to 1000 on the Arduino built-in Serial Monitor
  Serial.println(delayTime);
  
  // Turn on one by one inner square yellow LEDs
  for(int i=0;i<4;i++){
    digitalWrite(ledSquare[i], HIGH);
    delay(delayTime);
  }
  delay(500);
  
  // Turn off the whole yellow square
  for(int i=0;i<4;i++){
    digitalWrite(ledSquare[i], LOW);
  }
  
  // Turn on the inner left arrow and then the outer one, four times each
  for(byte i=0;i<4;i++){
    delay(delayTime);
    turnONinnerArrow(ledSquare[0], ledSquare[1], ledSquare[2]);
    delay(delayTime);
    digitalWrite(ledLeftArrow, HIGH);
    
    // Turn off both arrows
    delay(delayTime);
    turnOFFinnerArrow(ledSquare[0], ledSquare[1], ledSquare[2]);
    digitalWrite(ledLeftArrow, LOW);
  }
  
  // Do the same for right arrows
  for(byte i=0;i<4;i++){
    delay(delayTime);
    turnONinnerArrow(ledSquare[0], ledSquare[2], ledSquare[3]);
    delay(delayTime);
    digitalWrite(ledRightArrow, HIGH);
    delay(delayTime);
    turnOFFinnerArrow(ledSquare[0], ledSquare[2], ledSquare[3]);
    digitalWrite(ledRightArrow, LOW);
  }
  
  // Wait half a second and repeat
  delay(500);
}
