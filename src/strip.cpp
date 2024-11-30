#include "strip.h"

void Strip::setup(){
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds_, num_leds_);
    clear();
}

void Strip::set_one(CRGB color, size_t index){
    leds_[index] = color;
}

void Strip::set_color(CRGB color, size_t start, size_t count, size_t interval){
    for(size_t i = start; i < start + count; i += interval){
        set_one(color, i);
    }
}

void Strip::set_brightness(size_t brightness){
    FastLED.setBrightness(brightness);
}

void Strip::show(){
    FastLED.show();
}

void Strip::clear(){
    set_color(CRGB(0,0,0));
    set_brightness(0);
    show();
}