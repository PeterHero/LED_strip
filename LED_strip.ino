#include "strip_controller.h"

StripController strip;
CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
size_t colors_size = sizeof(colors) / sizeof(colors[0]);
constexpr size_t TIME = 500;

void setup() {
  strip.setup();
}

void loop() {
  strip.flash(colors, colors_size, TIME);
}
