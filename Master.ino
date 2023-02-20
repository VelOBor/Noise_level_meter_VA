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

// инициализируем библиотеку согласно распиновке 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// указываем прочие пины и инициализируем переменные
int mic_input_level = 0; //переменная уровня сигнала с микрофона
int micpin = A0; //пин микрофона, аналоговый выход с модуля микрофона

//выводы на светодиоды
int green_led = A5; 
int yellow_led = A4;
int red_led = A3;

//входы кнопок
int button1 = 8;
int button2 = 7;
int button3 = 6;

//переменные значения кнопок (1 = НЕ нажата, 0 = нажата)
int but1state = 0;
int but2state = 0;
int but3state = 0;

//разовое выполнение при запуске МК
void setup() {
// Указываем библиотеке сколько столбцов, строк на ЖК-дисплее:
  lcd.begin(20, 4);
//запускаем последовательный порт и указываем скорость
  Serial.begin(9600);
// указываем режимы работы пинов ввода/вывода
pinMode(micpin, INPUT);
pinMode(green_led, OUTPUT);
pinMode(yellow_led, OUTPUT);
pinMode(red_led, OUTPUT);

pinMode(button1, INPUT_PULLUP);
pinMode(button2, INPUT_PULLUP);
pinMode(button3, INPUT_PULLUP);


  // Выводим сообщение на ЖКД.
  lcd.print("Raw data from mic");
}


//основная часть программы
void loop() {
//читаем статус кнопок в переменные
  but1state = digitalRead(button1);
  but2state = digitalRead(button2);
  but3state = digitalRead(button3);
//каждый цикл программы начинаем с выключенных светодиодов
digitalWrite(green_led, LOW);
digitalWrite(yellow_led, LOW);
digitalWrite(red_led, LOW);
//читаем уровень сигнала с микрофона
mic_input_level = analogRead(micpin);
//если уровень сигнала выше чем..., зажигаем нужный светодиод
if (mic_input_level > 200) {digitalWrite(green_led, HIGH);}
if (mic_input_level > 300) {digitalWrite(yellow_led, HIGH);}
if (mic_input_level > 400) {digitalWrite(red_led, HIGH);}
//выводим значение кнопок (проверка их работы) и значенте уровня сигнала микрофона
//на последовательный порт на комп
Serial.print(but1state);
Serial.print(but2state);
Serial.print(but3state);
Serial.println(mic_input_level);

//выставляем курсор на столбец 0, строчку 1 ЖКД
//(примечание: строчка 1 на самом деле вторая строка, ибо отсчёт начинаем с нуля):
  lcd.setCursor(0, 1);
//выводим на ЖКД уровень сигнала микрофона
  lcd.print(mic_input_level);
//сдвигаем курсор
  lcd.setCursor(0, 2);
//и выводим сообщение
  lcd.print("Buttons=");
//снова сдвигаем курсор
  lcd.setCursor(10,2);
//и выводим значение переменных, сдвигаем курсор, следующая переменная и т. д.)
  lcd.print(but1state);
  lcd.setCursor(12,2);
  lcd.print(but2state);
  lcd.setCursor(14, 2);
  lcd.print(but3state);
}
