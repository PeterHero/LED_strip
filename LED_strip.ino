#include "src/strip_controller.h"
#include <SoftwareSerial.h>

StripController strip;
CRGB colors[] = {CRGB::Red, CRGB::Green, CRGB::Blue};
size_t colors_size = sizeof(colors) / sizeof(colors[0]);
constexpr size_t TIME = 500;

constexpr byte rxPin = 3;
constexpr byte txPin = 2;
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  strip.setup();
  strip.simple(CRGB::Blue, 10);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available() > 0) {
    bluetooth.readString();
    strip.simple(CRGB::Green, 10);
  }
  // strip.flash(colors, colors_size, TIME);
}
