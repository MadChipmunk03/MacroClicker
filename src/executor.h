#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <Adafruit_NeoPixel.h>
#include "macro.h"

class Executor {
    public:
        Executor(int macroCount, Adafruit_NeoPixel statusRGB);
        ~Executor();

        void addMacro(Macro newMacro);
        void selectNext();
        void selectPrevious();
        void executeSelected();

    private:
        void updateStatusRGB(); 

        int macroCount_; 
        Adafruit_NeoPixel statusRGB_;
        Macro* macros_; 
        int selectedIndex_ = -1; 
        int addedMacros_ = 0;
};

#endif // EXECUTOR_H