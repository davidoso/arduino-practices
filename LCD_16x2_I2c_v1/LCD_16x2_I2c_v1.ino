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


void setup() {
  // Initialize the lcd
  lcd.begin (20,4);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("**HELLO, WORLD**");
  lcd.setCursor(2,1);
  lcd.print("20x4 DISPLAY");
  lcd.scrollDisplayRight();
  delay(500);
}
