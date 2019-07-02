// MultiArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with

#include <FastLED.h>

#define pixelNum 52
CRGB first[pixelNum];
CRGB second[pixelNum];
CRGB third[pixelNum];
CRGB fourth[pixelNum];
CRGB fifth[pixelNum];
CRGB sixth[pixelNum];

const uint8_t pixelPin[] = {first[pixelNum], second[pixelNum], third[pixelNum], fourth[pixelNum], fifth[pixelNum], sixth[pixelNum]};

//Set the first and the last pixel number of the pixel strip
int firstPixel = 11;
int lastPixel = 22;

#define delayValue 80

// For mirroring strips, all the "special" stuff happens just in setup.  We
// just addLeds multiple times, once for each strip
void setup() {
  // tell FastLED there's 60 NEOPIXEL leds on pin 8-13
  setPixel();

}

void loop() {
  loopin();
}

void loopin() {
  for ( int i = firstPixel; i < lastPixel; i++ ) {
    first[i] = CRGB::Blue;
    FastLED.show();
    first[i] = CRGB::Black;
    delay(delayValue);
  }

}

void setPixel() {
  FastLED.addLeds<NEOPIXEL, 8>(first, pixelNum);
  FastLED.addLeds<NEOPIXEL, 9>(second, pixelNum);
  FastLED.addLeds<NEOPIXEL, 10>(third, pixelNum);
  FastLED.addLeds<NEOPIXEL, 11>(fourth, pixelNum);
  FastLED.addLeds<NEOPIXEL, 12>(fifth, pixelNum);
  FastLED.addLeds<NEOPIXEL, 13>(sixth, pixelNum);
}
