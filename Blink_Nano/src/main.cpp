#include <Arduino.h> // Обязательная строка для PlatformIO в файлах .cpp

void setup() {
  // Настраиваем пин встроенного светодиода как выход
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // Включаем светодиод
  delay(200);                       // Ждем 50 миллисекунд
  
  digitalWrite(LED_BUILTIN, LOW);  // Выключаем светодиод
  delay(200);                       // Ждем еще 50 миллисекунд
}