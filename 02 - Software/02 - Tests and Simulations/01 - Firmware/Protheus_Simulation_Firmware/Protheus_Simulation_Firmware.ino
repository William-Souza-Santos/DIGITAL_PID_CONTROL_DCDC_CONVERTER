/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

const int pwmPin = 9; // Pino para o PWM
float DUTY_CYCLE = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  
  // Configura o Timer1 para gerar PWM de 40 kHz
  TCCR1A = (1 << COM1A1) | (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10);
  ICR1 = 1600;  // Frequência de 40 kHz (16 MHz / 1600 = 10 kHz)
  OCR1A = 1000;  // 50% de duty cycle (800/1600)

  DUTY_CYCLE = (int)(((float)OCR1A / ICR1) * 100); // Cálculo correto do duty cycle

  lcd.begin(16, 2);
  lcd.print("DC DC CONVERTER");
  lcd.setCursor(2, 1);
  lcd.print("BUCK BOOST");  
  //delay(500); // Exibe a mensagem por 500 ms antes de limpar
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("DUTY CYCLE: ");
  lcd.print(DUTY_CYCLE, 1); // Exibe com uma casa decimal
  lcd.print("%  ");
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1);
}
