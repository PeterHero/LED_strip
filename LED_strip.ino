#include <FastLED.h>

constexpr int LED_PIN = 10;
constexpr int NUM_LEDS = 30;

CRGB leds[NUM_LEDS];

int R, G, B, r, g, b, brightness;

int DELAY = 500;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // slowly changing Green, Red and Blue
  G = 255;
  R = 0;
  B = 0;

  for(int i = 0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }

  for(int i = 0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(R, G, B);
  }

  for(int i = 0; i<=100; i += 10)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(DELAY);
  }

  for(int i = 100; i>=0; i -= 10)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(DELAY);
  }

  G = 0;
  R = 255;
  B = 0;

  for(int i = 0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }
  
  for(int i = 1; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(R, G, B);
  }

  for(int i = 0; i<=100; i += 10)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(DELAY);
  }

  for(int i = 100; i>=0; i -= 10)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(DELAY);
  }
  
  G = 0;
  R = 0;
  B = 255;

  for(int i = 0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }
  
  for(int i = 2; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(R, G, B);
  }

  for(int i = 0; i<=100; i += 10)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(DELAY);
  }

  for(int i = 100; i>=0; i -= 10)
  {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(DELAY);
  }
}