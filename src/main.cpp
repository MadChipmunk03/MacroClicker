#include <Arduino.h>
#include <DigiKeyboard.h> 
#include <Adafruit_NeoPixel.h>

#define LED_PIN 0
#define LED_COUNT 1
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 5

void setup() {
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);

  strip.begin();
  strip.setPixelColor(0, 255, 0, 128);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  strip.setPixelColor(0, 0, 0, 0);
  
  int button1State = digitalRead(BUTTON_1); // read the state of the pushbutton value
  if (button1State == LOW) {
    strip.setPixelColor(0, 255, 0, 0);
  }  
  int button2State = digitalRead(BUTTON_2); // read the state of the pushbutton value
  if (button2State == LOW) {
    strip.setPixelColor(0, 0, 255, 0);
  } 
  int button3State = digitalRead(BUTTON_3); // read the state of the pushbutton value
  if (button3State == LOW) {
    strip.setPixelColor(0, 0, 0, 255);
  }
  
  strip.show(); // Initialize all pixels to 'off'
  // DigiKeyboard.sendKeyStroke(0);

  // DigiKeyboard.println("Boom?");
  
  DigiKeyboard.delay(500);
}