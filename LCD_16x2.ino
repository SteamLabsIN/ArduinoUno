/*
 Base Code for 16X2 LCD
 Developed by- Harkrishan Singh (harkrishan@steamlabs.in)
*/

/*
  LiquidCrystal Library - Hello World

 Demonstrates how to use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
  * VSS to GND
  * VDD to 5V
  * V0 to 10K POT OUTPUT
  * RS pin to digital pin 12
  * R/W pin to GND
  * Enable(E) pin to digital pin 11
  * D4 pin to digital pin 5
  * D5 pin to digital pin 4
  * D6 pin to digital pin 3
  * D7 pin to digital pin 2
  * A to 5V with 220Ohm resistor
  * K to GND
  
  Adjust POT for Contrast
  
*/

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
