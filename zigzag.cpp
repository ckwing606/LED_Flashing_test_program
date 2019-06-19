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
#define stripLength     4


//Define Pins connected to WS2812 LED Strip
const uint8_t pixelPin[stripLength] = {8, 9, 10, 11};//, 12, 13};

//Define how many pixels for each strip
const uint8_t pixelNum[stripLength] = {57, 57, 56, 56};//, 57, 52};

//Setting up the address of LED Strips
Adafruit_NeoPixel strip[stripLength];

////Creating array to make pattern
//int LED_on_off_1[pixelNum];
//int LED_on_off_2[NUMPIXELS];
//int LED_on_off_3[NUMPIXELS];

int pixelCount = 0;
bool right = true;
#define maxPixel        57
const uint8_t anColor[3] = {60, 60, 255};
const uint8_t resetColor[3] = {0, 0, 0};
byte delayValue = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupPixel();
}


void loop() {
  // put your main code here, to run repeatedly:
  //lighter(4, anColor);
  zigZag(anColor);

}


void setupPixel() {
  for (unsigned int i = 0; i < stripLength; i++) {
    strip[i] = Adafruit_NeoPixel(pixelNum[i], pixelPin[i], NEO_GRB + NEO_KHZ800);
    strip[i].begin();
    strip[i].clear();
    strip[i].show();
  }
}


void lighter(uint8_t color[]) {

  for (int j = 0; j < stripLength; j++) {

    for (int i = 0; i < pixelNum[j]; i++) {
      strip[j].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
      strip[j].show();
      strip[j].clear();
      strip[j].show();
      delay(delayValue);
    }
  }

}

void zigZag(uint8_t color[]) {

  for (int i = 0; i < stripLength; i++) {
    if (right)
      pixelCount++;
    else
      pixelCount--;
    Serial.println("Forward");
    Serial.println(pixelCount);
    strip[i].setPixelColor(pixelCount, strip[i].Color(0, 255, 255));
    strip[i].show();
    delay(delayValue);
    strip[i].setPixelColor(pixelCount, strip[i].Color(0, 0, 0));
    strip[i].show();
    delay(delayValue);

  }

  for (int i = stripLength - 1; i >= 0; i--) {
    if (right)
      pixelCount++;
    else
      pixelCount--;
    Serial.println("Backward");
    Serial.println(pixelCount);
    strip[i].setPixelColor(pixelCount, strip[i].Color(255, 255, 0));
    strip[i].show();
    delay(delayValue);
    strip[i].setPixelColor(pixelCount, strip[i].Color(0, 0, 0));
    strip[i].show();
    delay(delayValue);
  }

  if ( pixelCount > maxPixel ) {
    right=false;
  } else if ( pixelCount < 0 ) {
    right=true;
    }
    
}
