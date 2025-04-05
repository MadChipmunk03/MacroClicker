#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

// Enum to represent button types
enum class ButtonType {
    NONE,
    LEFT,
    MIDDLE,
    RIGHT
};

// Function to get the currently pushed button
ButtonType getPushedButton();

#endif // BUTTONS_H