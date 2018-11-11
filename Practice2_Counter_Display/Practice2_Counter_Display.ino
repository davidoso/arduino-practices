/*
  0-15 Hexadecimal counter using a 7-segment display
  
Description:
  The display used is CC (cathode common), so the cathode connection of
  all the 7 inner diodes must be grounded (pin 3) and power must be
  applied to appropiate segments. Each of the seven LEDs is called a segment
  because when illuminated, the segment forms part of a numerical digit
  (both Decimal and Hex) to be displayed
  
Author:
  created September 07, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=Zp-mIKVb5ek
*/


// Output pins for all 7 segments (from 15 to 21)
byte a = 15, b = 16, c = 17, d = 18, e = 19, f = 20, g = 21;

// Arrays represents digits through 0-16. Each contains different segments of the display
byte dig0[] = { a, b, c, d, e, f },
  dig1[] = { b, c },
  dig2[] = { a, b, d, e, g },
  dig3[] = { a, b, c, d, g },
  dig4[] = { b, c, f, g },
  dig5[] = { a, c, d, f, g },
  dig6[] = { a, c, d, e, f, g },
  dig7[] = { a, b, c },
  dig8[] = { a, b, c, d, e, f, g },
  dig9[] = { a, b, c, f, g },
  digA[] = { a, b, c, e, f, g },
  digB[] = { c, d, e, f, g },
  digC[] = { a, e, d, f },
  digD[] = { b, c, d, e, g },
  digE[] = { a, e, d, f, g },
  digF[] = { a, e, f, g };

/*
 *  C does not support jagged arrays, so an array of byte pointers
 *  to the digit arrays aforementioned should be used
 *  THIS DOES NOT WORK. Arduino does not support jagged arrays :c
 */
/*byte *displayDigit[] = 
  { dg0, dg1, dg2, dg3, dg4, dg5, dg6, dg7, dg8, dg9, dgA, dgB, dgC, dgD, dgE, dgF };*/

// Default time in milliseconds before a digit changes
int delayTime = 1000;


void setup() {
  for(int i=a;i<g+1;i++){
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(9600); // Set rate for serial data transmission in bits per second (baud)
}

void displayDigit(byte arr[], byte arrSize) {
  for(int i=0;i<arrSize;i++){ // Turn on segments
    digitalWrite(arr[i], HIGH);
  }
  
  delay(delayTime); // Wait default time
  
  for(int i=0;i<arrSize;i++){ // Turn off segments
    digitalWrite(arr[i], LOW);
  }
}

void loop() {
  // For each digit, turn on and off corresponding segments
  displayDigit(dig0, sizeof(dig0));
  displayDigit(dig1, sizeof(dig1));
  displayDigit(dig2, sizeof(dig2));
  displayDigit(dig3, sizeof(dig3));
  displayDigit(dig4, sizeof(dig4));
  displayDigit(dig5, sizeof(dig5));
  displayDigit(dig6, sizeof(dig6));
  displayDigit(dig7, sizeof(dig7));
  displayDigit(dig8, sizeof(dig8));
  displayDigit(dig9, sizeof(dig9));
  displayDigit(digA, sizeof(digA));
  displayDigit(digB, sizeof(digB));
  displayDigit(digC, sizeof(digC));
  displayDigit(digD, sizeof(digD));
  displayDigit(digE, sizeof(digE));
  displayDigit(digF, sizeof(digF));
}
