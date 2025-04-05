#include "executor.h"
#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "macro.h"

Executor::Executor(int macroCount, Adafruit_NeoPixel statusRGB) 
    : macroCount_(macroCount), statusRGB_(statusRGB), macros_(new Macro[macroCount_]) {
}

Executor::~Executor() {
    delete[] macros_;
}

void Executor::addMacro(Macro newMacro) {
    if (addedMacros_ >= macroCount_) {
        return; // No more space for new macros
    }

    macros_[addedMacros_] = newMacro;

    // Select first macro if this is the first one added
    if (addedMacros_ == 0) {
        selectedIndex_ = 0;
        updateStatusRGB();
    }

    addedMacros_++;
}

void Executor::selectNext() {
    if (selectedIndex_ < addedMacros_ - 1) {
        selectedIndex_++;
    } else {
        selectedIndex_ = 0;
    }

    updateStatusRGB();
}

void Executor::selectPrevious() {
    if (selectedIndex_ > 0) {
        selectedIndex_--;
    } else {
        selectedIndex_ = addedMacros_ - 1;
    }

    updateStatusRGB();
}

void Executor::executeSelected() {
    macros_[selectedIndex_].Execute();
    updateStatusRGB();
}

void Executor::updateStatusRGB() {
    Macro::Color macroColor = macros_[selectedIndex_].GetColor();
    statusRGB_.setPixelColor(LED_PIN, macroColor.r, macroColor.g, macroColor.b);
    statusRGB_.show();
}