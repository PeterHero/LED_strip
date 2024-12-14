#include "src/strip_controller.h"
#include "src/bluetooth.h"

StripController strip;
CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
size_t colors_size = sizeof(colors) / sizeof(colors[0]);
constexpr size_t TIME = 500;

Bluetooth bt;

void setup() {
  strip.setup();
  strip.simple(CRGB::Blue, 10);

  bt.setup();
}

void loop() {
  String message;
  if (bt.read(message)) {
    strip.simple(CRGB::Green, 10);
  }
  // strip.flash(colors, colors_size, TIME);
}
