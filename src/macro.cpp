#include "macro.h"

Macro::Macro() {}

Macro::Macro(Color color, Script script) : color_(color), script_(script) {}

void Macro::Execute() {
    if (script_) {
        script_();
    }
}

Macro::Color Macro::GetColor() const {
    return color_;
}