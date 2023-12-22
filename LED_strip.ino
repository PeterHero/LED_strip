#include "strip_controller.h"

StripController strip;

void setup() {
  strip.setup();
  strip.simple(CRGB::Green);
}

void loop() {

}