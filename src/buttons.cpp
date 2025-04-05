#include <Arduino.h>
#include "config.h"

enum class ButtonType {
  NONE,
  LEFT,
  MIDDLE,
  RIGHT
};

ButtonType getPushedButton() {
  if (digitalRead(BUTTON_LEFT) == LOW) {
    return ButtonType::LEFT;
  } else if (digitalRead(BUTTON_MIDDLE) == LOW) {
    return ButtonType::MIDDLE;
  } else if (digitalRead(BUTTON_RIGHT) == LOW) {
    return ButtonType::RIGHT;
  }
  return ButtonType::NONE;
}