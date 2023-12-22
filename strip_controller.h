#ifndef STRIP_CONTROLLER_H
#define STRIP_CONTROLLER_H

#include "strip.h"

class StripController{
private:
    Strip strip;
public:
    void setup();
    void simple(CRGB color, size_t brightness = 100);
};

#endif