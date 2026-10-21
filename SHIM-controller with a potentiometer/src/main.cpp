#include <Arduino.h>

const int potPin = A0;  // Пин, куда подключен потенциометр
const int ledPin = 9;   // Пин ШИМ для светодиода

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 1. Считываем значение с потенциометра (0 ... 1023)
  int potValue = analogRead(potPin); 
  
  // 2. Переводим его в диапазон для ШИМ (0 ... 255)
  int brightness = map(potValue, 0, 1023, 0, 255); 
  
  // 3. Выдаем ШИМ-сигнал на светодиод
  analogWrite(ledPin, brightness); 
  
  delay(10); // Небольшая задержка для стабильности АЦП
}