#include <Arduino.h>

void setup() {
  pinMode(9, OUTPUT); // Настраиваем пин D9 на выход
}

void loop() {
  // Плавное разжигание светодиода
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(9, brightness);
    delay(10); // Скорость изменения яркости
  }

  // Плавное затухание светодиода
  for (int brightness = 64; brightness >= 0; brightness--) {
    analogWrite(9, brightness);
    delay(10);
  }
}