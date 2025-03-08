#include <Arduino.h>
#include <DigiKeyboard.h> 

void setup() {
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.println("Hello Digispark!");
  
  DigiKeyboard.delay(5000);
}