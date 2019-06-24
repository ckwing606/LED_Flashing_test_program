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
#define stripLength  6

//Set the first and the last pixel number of the pixel strip
int firstPixel = 11;
int lastPixel = 19;

//Define Pins connected to WS2812 LED Strip
const uint8_t pixelPin[] = {8, 9, 10, 11, 12, 13};

//Define how many pixels for each strip
const uint8_t pixelNum[] = {52, 52, 52, 52, 52, 52};

//const uint8_t lastArr = pixelNum[pixelNum.length - 1];

//Setting up the address of LED Strips
Adafruit_NeoPixel strip[stripLength];

//Define a counter to creat pattern on the strip
int pixelCount = 0;

//Define pixel color with R, G, B value
const uint8_t pixelColor[3] = {0, 80, 255};

//Set the pixel color to black
const uint8_t resetColor[3] = {0, 0, 0};

//Set delay time for each pixel
int delayValue = 600;

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

  //tester(pixelColor, resetColor);
  looper(pixelColor, resetColor);
  
  Serial.println("----------Loop finished!----------");
  //delayValue = 500;
  firstStrip += 1;
  lastStrip -= 1;
  firstPixel += 1;
  lastPixel -= 1;
  
}

void setupPixel() {
  for (unsigned int i = 0; i < stripLength; i++) {
    strip[i] = Adafruit_NeoPixel(pixelNum[i], pixelPin[i], NEO_GRB + NEO_KHZ800);
    strip[i].begin();
    strip[i].clear();
    strip[i].show();
  }
}


void looper(uint8_t color[3], uint8_t reset[3]) {

  for (int i = firstPixel; i < lastPixel; i++) {
    strip[firstStrip].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
    strip[firstStrip].show();
    delay(delayValue);
    strip[firstStrip].setPixelColor(i, strip[i].Color(reset[0], reset[1], reset[2]));
    strip[firstStrip].show();
    Serial.print("firstStrip: ");
    Serial.print(firstStrip);
    Serial.print(",");
    Serial.println(i);
  }

  for (int i = firstStrip; i < lastStrip ; i++) {
    strip[i].setPixelColor(lastPixel, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
    strip[i].setPixelColor(lastPixel, strip[i].Color(reset[0], reset[1], reset[2]));
    strip[i].show();
    Serial.print("from left to right: ");
    Serial.print(lastPixel);
    Serial.print(",");
    Serial.println(i);
  }

  for ( int i = lastPixel; i > firstPixel; i--) {
    strip[lastStrip].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
    strip[lastStrip].show();
    delay(delayValue);
    strip[lastStrip].setPixelColor(i, strip[i].Color(reset[0], reset[1], reset[2]));
    strip[lastStrip].show();
    Serial.print("lastStrip: ");
    Serial.print(lastStrip);
    Serial.print(",");
    Serial.println(i);
  }

  for (int i = lastStrip ; i > firstStrip; i--) {
    strip[i].setPixelColor(firstPixel, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
    strip[i].setPixelColor(firstPixel, strip[i].Color(reset[0], reset[1], reset[2]));
    strip[i].show();
    Serial.print("from right to left: ");
    Serial.print(firstPixel);
    Serial.print(",");
    Serial.println(i);
  }

}

void tester(uint8_t color[3], uint8_t reset[3]) {

    for (int i = firstPixel; i < lastPixel; i++) {
    strip[firstStrip].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
    strip[firstStrip].show();
    delay(delayValue);
//    strip[firstStrip].setPixelColor(i, strip[i].Color(reset[0], reset[1], reset[2]));
//    strip[firstStrip].show();
    Serial.print("firstStrip: ");
    Serial.print(firstStrip);
    Serial.print(",");
    Serial.println(i);
  }




/*
  for (int i = firstStrip; i < lastStrip ; i++) {
    strip[i].setPixelColor(lastPixel, strip[i].Color(color[0], color[1], color[2]));
    strip[i].show();
    delay(delayValue);
//    strip[i].setPixelColor(lastPixel, strip[i].Color(reset[0], reset[1], reset[2]));
//    strip[i].show();
    Serial.print("from left to right: ");
    Serial.print(lastPixel);
    Serial.print(",");
    Serial.println(i);
  }

   for ( int i = lastPixel; i > firstPixel; i--) {
    strip[lastStrip].setPixelColor(i, strip[i].Color(color[0], color[1], color[2]));
    strip[lastStrip].show();
    delay(delayValue);
//    strip[lastStrip].setPixelColor(i, strip[i].Color(reset[0], reset[1], reset[2]));
//    strip[lastStrip].show();
    Serial.print("lastStrip: ");
    Serial.print(lastStrip);
    Serial.print(",");
    Serial.println(i);
  }
*/
  
}
