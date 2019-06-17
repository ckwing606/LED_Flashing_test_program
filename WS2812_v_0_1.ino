//Include the library and config
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

//Define the total number of LED Strip
#define stripLength     6

//Define Pins connected to WS2812 LED Strip
const uint16_t pixelPin[stripLength] = {8, 9, 10, 11, 12, 13};

//Define how many pixels for each strip
const uint16_t pixelNum[stripLength] = {50, 50, 50, 50, 50, 50};

//Setting up the address of LED Strips
Adafruit_NeoPixel strip[stripLength];

//Creating array to make pattern
//int LED_on_off_1[NUMPIXELS];
//int LED_on_off_2[NUMPIXELS];
//int LED_on_off_3[NUMPIXELS];


void setup() {
  // put your setup code here, to run once:
    setupPixel();
}


void loop() {
  // put your main code here, to run repeatedly:
    lighter();
    
}


void setupPixel(){
  for (unsigned int i = 0; i < stripLength; i++){
    strip[i] = Adafruit_NeoPixel(pixelNum[i], pixelPin[i], NEO_GRB + NEO_KHZ800);
    strip[i].begin();
    strip[i].clear();
    strip[i].show();
  }
}


void lighter(){

    int R = 50;
    int G = 100;
    int B = 150;
    
    for (int j = 0; j < stripLength; j++){
  
      for (int i = 0; i < pixelNum[j]; i++){
      strip[j].setPixelColor(i, strip[i].Color(R, G, B));
      strip[j].show();
      strip[j].clear();
      //delay(10);
      }
  }

}
