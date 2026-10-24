#include <Arduino.h>

// Данный код работает без фиксации кнопки (жмешь - горит, отпустил - гаснет)

const int BUTTON_PIN = 2; // Пин кнопки (с внутренней подтяжкой)
const int LED_PIN = 13;   // Пин светодиода

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // Принудительно заявляем внутреннюю подтяжку, раз плата ее использует
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}

void loop() {
  // Считываем состояние. Если кнопка нажата — на пине жесткий 0В (LOW)
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH); // Включаем светодиод, пока держим кнопку
  } else {
    digitalWrite(LED_PIN, LOW);  // Выключаем светодиод, как только отпустили
  }
}

//Данный код работает как триггер (нажал - загорелся и горит, нажал еще раз - погас)

// #include <Arduino.h>

// // Объявляем пины для периферии
// const int BUTTON_PIN = 2; // Пин, к которому подключена кнопка
// const int LED_PIN = 13;   // Пин встроенного (или внешнего) светодиода

// void setup() {
//   // Конфигурируем пин светодиода как выход
//   pinMode(LED_PIN, OUTPUT);
  
//   // Конфигурируем пин кнопки как вход
//   pinMode(BUTTON_PIN, INPUT);
// }

// void loop() {
//   // Считываем текущее состояние кнопки
//   int buttonState = digitalRead(BUTTON_PIN);

//   // Так как используется внешняя подтяжка к 5V (Pull-Up),
//   // при нажатии на кнопку на пине будет уровень LOW.
//   if (buttonState == LOW) {
//     digitalWrite(LED_PIN, HIGH); // Включаем светодиод
//   } else {
//     digitalWrite(LED_PIN, LOW);  // Выключаем светодиод
//   }
// }