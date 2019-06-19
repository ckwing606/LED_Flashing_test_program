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
#define stripLength     5


//Define Pins connected to WS2812 LED Strip
const uint8_t pixelPin[] = {8, 9, 10, 11, 12, 13};

//Define how many pixels for each strip
const uint8_t pixelNum[] = {57, 57, 56, 56, 57, 52};

//Setting up the address of LED Strips
Adafruit_NeoPixel strip[stripLength];

//Define a counter to creat pattern on the strip
int pixelCount = 0;

//Set the maximum pixel number of the pixel strip
#define maxPixel        57

//Define pixel color with R, G, B value
const uint8_t pixelColor[3] = {60, 255, 255};  
 
//Set the pixel color to black
const uint8_t resetColor[3] = {0, 0, 0};  

//Set delay time for each pixel
byte delayValue = 1000;   

bool right = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupPixel();
}


void loop() {
  // put your main code here, to run repeatedly:
  //lighter(4, anColor);
  zigZag(pixelColor, resetColor);

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

void zigZag(uint8_t color[], uint8_t reset[]) {

  for (int i = 0; i < stripLength; i++) {
    //backwardChecker();
    pixelLooper();
    Serial.println("Forward");
    Serial.println(pixelCount);
    strip[i].setPixelColor(pixelCount, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
    strip[i].setPixelColor(pixelCount, strip[i].Color(reset[0], reset[1], reset[2]));
    strip[i].show();
    delay(delayValue);

  }

  for (int i = stripLength - 2; i > 0; i--) {
    //backwardChecker();
    pixelLooper();
    Serial.println("Backward");
    Serial.println(pixelCount);
    strip[i].setPixelColor(pixelCount, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
    strip[i].setPixelColor(pixelCount, strip[i].Color(reset[0], reset[1], reset[2]));
    strip[i].show();
    delay(delayValue);
  }
  //backward();
}

void backward() {

  if ( pixelCount > maxPixel ) {
    right = false;
  } else if ( pixelCount < 0 ) {
    right = true;
  }

}
void backwardChecker() {
  if (right)
    pixelCount++;
  else
    pixelCount--;
}

void pixelLooper() {
  pixelCount++;

  if (pixelCount > maxPixel) {
    pixelCount = 0;
  }
}
