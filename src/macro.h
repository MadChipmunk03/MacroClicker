#ifndef MACRO_H
#define MACRO_H

#include <stdint.h>

class Macro {
    public:
        struct Color {
            uint8_t r, g, b;
        };
    
        using Script = void (*)();

        Macro();
        Macro(Color color, Script script);
    
        void Execute();
        Color GetColor() const;
    
    private:
        Color color_;
        Script script_;
};

#endif // MACRO_H