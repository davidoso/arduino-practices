/*
  LED Arrows blinking counter
  
Description:
  This code is a combination between Practice1_Led_Arrows and
  Practice2_Counter_Display codes. The display is a 0-15 hexadecimal
  counter, so it has 16 possible values. There are 2 left arrows
  (inner and outer) and 2 right arrows arranged the same fashion.
  Each arrow blinks 4 times while the numbering appear on the display.
  The potentiometer is not used
  
Author:
  created September 13, 2017
  by David Osorio
  
Organization:
  Colima Institute of Technology
  
Career:
  Computer Engineering
  
Subject:
  Embedded Systems
  
Video evidence:
  https://www.youtube.com/watch?v=b7xwigtMOzk
*/


/*
 * These macros reduce the lines of codes in the loop method
 * because everytime a digit changes on the display, a specific
 * arrow blinks (turns on and off).
 * HIGH means 0x1 and LOW 0x0, i.e., they have a integer value
 */
#define macroInnerArrows(arrow, dig)\
{\
  turnOnOrOffInnerArrow(arrow, HIGH);\
  displayDigit(dig, sizeof(dig), HIGH);\
  delay(1000);\
  turnOnOrOffInnerArrow(arrow, LOW);\
  displayDigit(dig, sizeof(dig), LOW);\
}\

#define macroOuterArrows(arrow, dig)\
{\
  digitalWrite(arrow, HIGH);\
  displayDigit(dig, sizeof(dig), HIGH);\
  delay(1000);\
  digitalWrite(arrow, LOW);\
  displayDigit(dig, sizeof(dig), LOW);\
}\


/*
 *  The following array represent each vertex of the inner square.
 *  Each index depicts a LED blinking counterclockwise. Index 0 is the top LED.
 *  They turn on and off at different times
 */
byte innerLeftArrow[] = { 7, 6, 5 };
byte innerRightArrow[] = { 7, 5, 4 };

/*
 * These two pins are the outer arrows. Each one has 3 LEDs attached.
 * All the LEDs blink at the same time, so only one output pin is needed
 */
byte outerLeftArrow = 3;
byte outerRightArrow = 2;

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


void setup() {
  for(int i=2;i<8;i++){
    pinMode(i, OUTPUT);
  }
  
  for(int i=a;i<g+1;i++){
    pinMode(i, OUTPUT);
  }
}

// This turns either on or off leds for either left or right arrow
void turnOnOrOffInnerArrow(byte arr[], int value) {
  for(int i=0;i<3;i++){
    digitalWrite(arr[i], value);
  }
}

// Depending on the array digit, turn either on or off the segments
void displayDigit(byte arr[], byte arrSize, int value) {
  for(int i=0;i<arrSize;i++){
    digitalWrite(arr[i], value);
  }
}

void loop() {
  /* Use macros to turn on the inner left arrow first,
  and then the outer one. Four times each */
  macroInnerArrows(innerLeftArrow, dig0);
  macroOuterArrows(outerLeftArrow, dig1);
  macroInnerArrows(innerLeftArrow, dig2);
  macroOuterArrows(outerLeftArrow, dig3);
  macroInnerArrows(innerLeftArrow, dig4);
  macroOuterArrows(outerLeftArrow, dig5);
  macroInnerArrows(innerLeftArrow, dig6);
  macroOuterArrows(outerLeftArrow, dig7);
  
  // Do the same for right arrows
  macroInnerArrows(innerRightArrow, dig8);
  macroOuterArrows(outerRightArrow, dig9);
  macroInnerArrows(innerRightArrow, digA);
  macroOuterArrows(outerRightArrow, digB);
  macroInnerArrows(innerRightArrow, digC);
  macroOuterArrows(outerRightArrow, digD);
  macroInnerArrows(innerRightArrow, digE);
  macroOuterArrows(outerRightArrow, digF);
}
