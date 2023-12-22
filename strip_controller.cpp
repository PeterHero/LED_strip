#include "strip_controller.h"

void StripController::setup(){
    strip.setup();
}

void StripController::simple(CRGB color, size_t brightness){
    strip.set_color(color);
    strip.set_brightness(brightness);
    strip.show();
}