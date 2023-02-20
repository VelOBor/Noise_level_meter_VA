/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int mic_input_level = 0;
int micpin = A0;
int green_led = A5;
int yellow_led = A4;
int red_led = A3;
int button1 = 8;
int button2 = 7;
int button3 = 6;

int but1state = 0;
int but2state = 0;
int but3state = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  Serial.begin(9600);
pinMode(micpin, INPUT);
pinMode(green_led, OUTPUT);
pinMode(yellow_led, OUTPUT);
pinMode(red_led, OUTPUT);

pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);
pinMode(button3, INPUT_PULLUP);


  // Print a message to the LCD.
  lcd.print("Raw data from mic");
}

void loop() {
  but1state = digitalRead(button1);
  but2state = digitalRead(button2);
  but3state = digitalRead(button3);
digitalWrite(green_led, LOW);
digitalWrite(yellow_led, LOW);
digitalWrite(red_led, LOW);
  mic_input_level = analogRead(micpin);
if (mic_input_level > 200) {digitalWrite(green_led, HIGH);}
if (mic_input_level > 300) {digitalWrite(yellow_led, HIGH);}
if (mic_input_level > 400) {digitalWrite(red_led, HIGH);}

  // put your main code here, to run repeatedly:

Serial.print(but1state);
Serial.print(but2state);
Serial.print(but3state);
Serial.println(mic_input_level);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(mic_input_level);
  lcd.setCursor(0, 2);
  lcd.print("Buttons=");
  lcd.setCursor(10,2);
  lcd.print(but1state);
  lcd.setCursor(12,2);
  lcd.print(but2state);
  lcd.setCursor(14, 2);
  lcd.print(but3state);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}
