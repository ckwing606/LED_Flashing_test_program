// MultipleStripsInOneArray - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up four NEOPIXEL strips on three
// different pins, each strip will be referring to a different part of the single led array

#include <FastLED.h>

#define NUM_STRIPS 3
#define NUM_LEDS_PER_STRIP 57
#define NUM_LEDS NUM_LEDS_PER_STRIP * NUM_STRIPS

CRGB leds[NUM_LEDS];

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {

  // tell FastLED there's 60 NEOPIXEL leds on pin 10, starting at index 0 in the led array
  FastLED.addLeds<NEOPIXEL, 8>(leds, 0, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11, starting at index 60 in the led array
  FastLED.addLeds<NEOPIXEL, 9>(leds, 0, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12, starting at index 120 in the led array
  FastLED.addLeds<NEOPIXEL, 10>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 10, starting at index 0 in the led array
  FastLED.addLeds<NEOPIXEL, 11>(leds, NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 11, starting at index 60 in the led array
  FastLED.addLeds<NEOPIXEL, 12>(leds, 2 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);

  // tell FastLED there's 60 NEOPIXEL leds on pin 12, starting at index 120 in the led array
  FastLED.addLeds<NEOPIXEL, 13>(leds, 2 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);

}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(50, 180, 120);
    FastLED.show();
    leds[i] = CRGB(7, 7, 7);
    delay(0.01);
  }

  for (int i = NUM_LEDS; i >= 0 ; i--) {
    leds[i] = CRGB(50, 180, 120);
    FastLED.show();
    leds[i] = CRGB(7, 7, 7);
    delay(0.01);
  }
}

/*#include <FastLED.h>
  #define LED_PIN     8
  #define NUM_LEDS    57
  #define delayVal    15



  CRGB leds[NUM_LEDS];
  void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  }
  void loop() {

  for (int i = 0 ; i < NUM_LEDS ; i++) {
    leds[i] = CRGB(0, 0, 150);
    FastLED.show();
    delay(delayVal);
  }

  for (int i = NUM_LEDS ; i >= 0 ; i--) {
    leds[i] = CRGB(150, 0, 0);
    FastLED.show();
    delay(delayVal);
  }
  }*/
