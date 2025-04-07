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

void setup() {
  pinMode(BUTTON_MIDDLE, INPUT);

  statusRGB.begin();
  statusRGB.setPixelColor(LED_PIN, 0, 0, 255);
  statusRGB.show();

  Macro macro1({64, 0, 0}, script1);

  executor.addMacro(macro1);
}

void waitForButtonRelease() {
  while (getPushedButton() != ButtonType::NONE) {
    DigiKeyboard.delay(100);
  }
}

void loop() {
  ButtonType pushedButton = getPushedButton();

  if (pushedButton == ButtonType::LEFT) {
    executor.executeSelected();
    waitForButtonRelease();
  }

  // if(pushedButton == ButtonType::LEFT) {
  //   executor.selectPrevious();
  //   waitForButtonRelease();
  // } else if (pushedButton == ButtonType::MIDDLE) {
  //   executor.executeSelected();
  //   waitForButtonRelease();
  // } else if (pushedButton == ButtonType::RIGHT) {
  //   executor.selectNext();
  //   waitForButtonRelease();
  // }

  DigiKeyboard.delay(100);
}