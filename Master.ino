/*
Адаптировано из LiquidCrystal Library - Hello World (из примеров в Arduino IDE). 
Скетч переписан под LCD2004 с оригинального LCD1602
  Распиновка согласно схеме (ВНИМАНИЕ!!! Нумерация пинов Arduino ОТЛИЧАЕТСЯ от
  ФИЗИЧЕСКИХ пинов atmega328, смотреть картинку Pinout_of_Arduino...)
 * LCD RS на пин 12
 * LCD Enable на пин 11
 * LCD D4 на пин 5
 * LCD D5 на пин 4
 * LCD D6 на пин 3
 * LCD D7 на пин 2
 * LCD R/W на GND 
 * LCD VSS на GND
 * LCD VCC на  +5V
 * 10K потенциометр - концы на +5V и GND,
  щётка на LCD VO (пин 3)
Библиотека: 
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
 Оригинальный пример находится в публичном доступе.
 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// подключаем библиотеку:
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
