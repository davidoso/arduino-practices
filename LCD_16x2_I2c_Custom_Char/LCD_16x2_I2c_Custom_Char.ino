// Created Nov. 14, 2017
// by David Osorio

#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // F Malpartida's NewliquidCrystal_1.3.4 library

// This macro sets the LCD I2C address
// Define I2C Address (upload I2C_Scanner.ino first to make sure. Usually it's 0x27)
#define I2C_ADDR    0x27

// Set the LCD address to 0x27 for a 20 chars, 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// This macro displays and scrolls 3 custom symbols for each of the 4 rows (not 2 lines)
#define macroWriteAndScroll\
{\
  lcd.write((byte)0);\
  lcd.write((byte)1);\
  lcd.write((byte)0);\
  for(int c=0;c<17;c++){\
    lcd.scrollDisplayRight();\
    delay(500);\
  }\
  lcd.clear();\
}\

byte symSwastika[] = {
  B00000,
  B00110,
  B10100,
  B11111,
  B00101,
  B01100,
  B00000,
  B00000
};

byte symTeacher[] = {
  B11111,
  B10001,
  B10101,
  B10101,
  B10101,
  B10101,
  B10001,
  B11111
};


void setup() {
  // Reference:
  // You should define the chars AFTER calling lcd.begin()
  // https://forum.arduino.cc/index.php?topic=397754.0
  
  // Initialize the lcd and create custom symbols
  lcd.begin (20,4);
  lcd.createChar(0, symSwastika);
  lcd.createChar(1, symTeacher);
  lcd.clear();
}

void loop() {
  macroWriteAndScroll // Row 1 (line 0)
  
  lcd.setCursor(0,1); // Row 2 (line 1)
  macroWriteAndScroll
  
  lcd.setCursor(20,0); // Row 3 (line 0)
  macroWriteAndScroll
  
  lcd.setCursor(20,1); // Row 4 (line 1)
  macroWriteAndScroll
}
