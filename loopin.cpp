/*
  Program name: WS2812 ZigZag
  Author:       Robin
  Date:         2019-06-19

*/

//Include the library and config
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

//Define the total number of LED Strip
#define stripLength     6


//Define Pins connected to WS2812 LED Strip
const uint8_t pixelPin[] = {8, 9, 10, 11, 12, 13};

//Define how many pixels for each strip
const uint8_t pixelNum[] = {52, 52, 52, 52, 52, 52};

//const uint8_t lastArr = pixelNum[pixelNum.length - 1];

//Setting up the address of LED Strips
Adafruit_NeoPixel strip[stripLength];

//Define a counter to creat pattern on the strip
int pixelCount = 0;

//Set the maximum pixel number of the pixel strip
#define firstPixel      11
#define maxPixel        30

//Define pixel color with R, G, B value
const uint8_t pixelColor[3] = {60, 0, 255};

//Set the pixel color to black
const uint8_t resetColor[3] = {255, 0, 0};

//Set delay time for each pixel
byte delayValue = 4;

//For looper() function
uint8_t firstStrip = 0;
uint8_t lastStrip = stripLength - 1;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupPixel();
}


void loop() {
  // put your main code here, to run repeatedly:

  looper(pixelColor);
  
}


void setupPixel() {
  for (unsigned int i = 0; i < stripLength; i++) {
    strip[i] = Adafruit_NeoPixel(pixelNum[i], pixelPin[i], NEO_GRB + NEO_KHZ800);
    strip[i].begin();
    strip[i].clear();
    strip[i].show();
  }
}


void looper(uint8_t color[3]) {

  for (int i = firstPixel; i < maxPixel; i++) {
    strip[firstStrip].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
    strip[firstStrip].show();
    delay(delayValue);
    strip[firstStrip].clear();
    strip[firstStrip].show();
  }

  for (int i = 0; i < stripLength; i++) {
    strip[i].setPixelColor(maxPixel - 1, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
    strip[i].clear();
    strip[i].show();
  }

  for ( int i = maxPixel - 1; i >= firstPixel; i--) {
    strip[lastStrip].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
    strip[lastStrip].show();
    delay(delayValue);
    strip[lastStrip].clear();
    strip[lastStrip].show();
  }

  for (int i = stripLength; i > 0; i--) {
    strip[i].setPixelColor(firstPixel, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
    strip[i].clear();
    strip[i].show();
  }
}
