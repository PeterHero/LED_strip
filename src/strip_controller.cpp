#include "strip_controller.h"

void StripController::static_brightness(size_t brightness){
    strip.set_brightness(brightness);
    strip.show();
}

void StripController::up_down_brightness(size_t steps, size_t time, size_t max){
    for (size_t i = 0; i < steps; ++i)
    {
        strip.set_brightness(max * i / steps);
        strip.show();
        delay(time);
    }

    for (size_t i = steps; i > 0; --i)
    {
        strip.set_brightness(max * i / steps);
        strip.show();
        delay(time);
    }
    
    strip.clear();
}

void StripController::setup(){
    strip.setup();
}

void StripController::simple(CRGB color, size_t brightness){
    strip.set_color(color);
    static_brightness(brightness);
}

void StripController::flash(CRGB color, size_t time){
    strip.set_color(color);
    up_down_brightness(10, time);
}

void StripController::flash(CRGB* colors, size_t count, size_t time){
    for (size_t i = 0; i < count; ++i)
    {
        flash(colors[i], time);
    }
}