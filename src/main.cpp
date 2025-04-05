#include <Arduino.h>
#include <DigiKeyboard.h> 
#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "buttons.h"
#include "macro.h"
#include "executor.h"

Adafruit_NeoPixel statusRGB(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Executor executor(3, statusRGB);

void script1() {
  statusRGB.setPixelColor(LED_PIN, 255, 255, 0);
  statusRGB.show();
  DigiKeyboard.write("Hello from script 1!");
}
void script2() {
  statusRGB.setPixelColor(LED_PIN, 0, 255, 255);
  statusRGB.show();
  DigiKeyboard.write("Hello from script 2!");
}
void script3() {
  statusRGB.setPixelColor(LED_PIN, 255, 0, 255);
  statusRGB.show();
  DigiKeyboard.write("Hello from script 3!");
}

void setup() {
  pinMode(BUTTON_LEFT, INPUT);
  pinMode(BUTTON_MIDDLE, INPUT);
  pinMode(BUTTON_RIGHT, INPUT);

  statusRGB.begin();

  Macro macro1({64, 0, 0}, script1);
  Macro macro2({0, 64, 0}, script2);
  Macro macro3({0, 0, 64}, script3);

  executor.addMacro(macro1);
  executor.addMacro(macro2);
  executor.addMacro(macro3);
}

void waitForButtonRelease() {
  while (getPushedButton() != ButtonType::NONE) {
    DigiKeyboard.delay(100);
  }
}

void loop() {
  ButtonType pushedButton = getPushedButton();

  if(pushedButton == ButtonType::LEFT) {
    executor.selectPrevious();
    waitForButtonRelease();
  } else if (pushedButton == ButtonType::MIDDLE) {
    executor.executeSelected();
    waitForButtonRelease();
  } else if (pushedButton == ButtonType::RIGHT) {
    executor.selectNext();
    waitForButtonRelease();
  }

  DigiKeyboard.delay(100);
}