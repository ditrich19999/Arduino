#include <Arduino.h>

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);
}

void loop() {
  // 1. Включаем полный ход вперед на 0,5 секунды
  myServo.write(179); 
  delay(500);

  // 2. Полный стоп (тормоз) на 2 секунды
  myServo.write(90); 
  delay(2000);

  // 3. Плавный ход назад на 3 секунды
  myServo.write(80); 
  delay(3000);

  // 4. Снова стоп на 2 секунды
  myServo.write(90); 
  delay(2000);
}