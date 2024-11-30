#ifndef STRIP_H
#define STRIP_H

#include <FastLED.h>

#ifndef LED_PIN
#define LED_PIN 10
#endif

#ifndef NUM_LEDS
#define NUM_LEDS 30
#endif

class Strip {
private:
    static constexpr size_t pin_ = LED_PIN;
    static constexpr size_t num_leds_ = NUM_LEDS;
    CRGB leds_[NUM_LEDS];
public:
    void setup();
    void set_one(CRGB color, size_t index);
    void set_color(CRGB color, size_t start = 0, size_t count = num_leds_, size_t interval = 1);
    void set_brightness(size_t birghtness = 100);
    void show();
    void clear();
};

#endif