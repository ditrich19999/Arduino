#include <Arduino.h>

const int buttonPin = 2;    // Кнопка на пине D2
const int ledPin = 13;      // Встроенный светодиод на плате

int ledState = LOW;         // Текущее состояние светодиода
int lastButtonState = HIGH; // Предыдущее считанное состояние кнопки (HIGH из-за PULLUP)

unsigned long lastDebounceTime = 0;  // Время последнего изменения сигнала
unsigned long debounceDelay = 50;    // Время ожидания, пока дребезг утихнет (50 мс)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Включаем внутреннюю подтяжку к 5В
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  // Считываем текущее состояние кнопки
  int reading = digitalRead(buttonPin);

  // Если сигнал изменился (из-за нажатия или из-за дребезга)
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Сбрасываем таймер дребезга
  }

  // Если с момента последнего шума прошло времени больше, чем задержка дебаунса
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // То это значение стабильно. Проверяем, изменилось ли состояние кнопки
    if (reading == LOW) { // Если кнопка прижата к GND (нажата)
      // Инвертируем состояние светодиода
      ledState = !ledState; 
      digitalWrite(ledPin, ledState);
      
      // Чтобы не переключать бесконечно, пока кнопка зажата, 
      // ждем, пока ее отпустят (в рамках логики дебаунса)
      while(digitalRead(buttonPin) == LOW) { delay(5); }
    }
  }

  // Запоминаем значение для следующего цикла loop
  lastButtonState = reading;
}