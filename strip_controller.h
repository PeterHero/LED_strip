#ifndef STRIP_CONTROLLER_H
#define STRIP_CONTROLLER_H

#include "strip.h"

class StripController{
private:
    Strip strip;
    void static_brightness(size_t brightness);
    void up_down_brightness(size_t steps, size_t delay, size_t max = 100);
public:
    void setup();
    void simple(CRGB color, size_t brightness = 100);
    void flash(CRGB color, size_t time);
    void flash(CRGB* colors, size_t count, size_t time);
};

#endif