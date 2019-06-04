// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define S1      8 // On Trinket or Gemma, suggest changing this to 1
#define S2      9
#define S3      10
#define S4      11
#define S5      12
#define S6      13


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 50 // Popular NeoPixel ring size
int LED_on_off_1[NUMPIXELS] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; //NUMPIXELS = 50, so, init 50 elements.
int LED_on_off_2[NUMPIXELS] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}; //NUMPIXELS = 50, so, init 50 elements.
int LED_on_off_3[NUMPIXELS] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; //NUMPIXELS = 50, so, init 50 elements.
int LED_on_off_4[NUMPIXELS] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}; //NUMPIXELS = 50, so, init 50 elements.
int LED_on_off_5[NUMPIXELS] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}; //NUMPIXELS = 50, so, init 50 elements.
int LED_on_off_6[NUMPIXELS] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}; //NUMPIXELS = 50, so, init 50 elements.

int pixels_color_1 = {40, 0, 50};
int pixels_color_2 = {100, 50, 0};
int pixels_color_3 = {80, 130, 0};
int pixels_color_4 = {100, 100, 100};
int pixels_color_5 = {0, 0, 180};
int pixels_color_6 = {0, 80, 50};

int LED_on_off = {
  LED_on_off_1[NUMPIXELS],
  LED_on_off_2[NUMPIXELS],
  LED_on_off_3[NUMPIXELS],
  LED_on_off_4[NUMPIXELS],
  LED_on_off_5[NUMPIXELS],
  LED_on_off_6[NUMPIXELS]
};

int pixels_color = {
  pixels_color_1,
  pixels_color_2,
  pixels_color_3,
  pixels_color_4,
  pixels_color_5,
  pixels_color_6
};




// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels1(NUMPIXELS, S1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, S2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, S3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, S4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS, S5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels6(NUMPIXELS, S6, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 40 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin();
  pixels3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels4.begin();
  pixels5.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels6.begin();

  pixels1.clear(); // Set all pixel colors to 'off'
  pixels2.clear();
  pixels3.clear(); // Set all pixel colors to 'off'
  pixels4.clear();
  pixels5.clear(); // Set all pixel colors to 'off'
  pixels6.clear();

  pixels1.show();  // Send the updated pixel colors to the hardware.
  pixels2.show();
  pixels3.show();  // Send the updated pixel colors to the hardware.
  pixels4.show();
  pixels5.show();  // Send the updated pixel colors to the hardware.
  pixels6.show();


  delay(1000);
}

void loop() {
  pixels1.clear(); // Set all pixel colors to 'off'
  pixels2.clear();
  pixels3.clear(); // Set all pixel colors to 'off'
  pixels4.clear();
  pixels5.clear(); // Set all pixel colors to 'off'
  pixels6.clear();

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i <= NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255

    setPixelColor(NUMPIXELS);

    delay(DELAYVAL);
  }
  /*
      if ( i%2 == 0 ){
      pixels1.setPixelColor(i, pixels1.Color(40, 0, 50));
      pixels2.setPixelColor(i, pixels2.Color(0, 15, 60));
      pixels3.setPixelColor(i, pixels3.Color(40, 0, 50));
      pixels4.setPixelColor(i, pixels4.Color(0, 15, 60));
      pixels5.setPixelColor(i, pixels5.Color(40, 0, 50));
      pixels6.setPixelColor(i, pixels6.Color(0, 15, 60));

      pixels1.show();   // Send the updated pixel colors to the hardware.
      pixels2.show();
      pixels3.show();   // Send the updated pixel colors to the hardware.
      pixels4.show();
      pixels5.show();   // Send the updated pixel colors to the hardware.
      pixels6.show();

      delay(DELAYVAL);
  */
  //delay(3000);
}

void setPixelColor(NUMPIXELS) {
  //Set function
  int pixels = 1;

  for (int i = 0; i < 6; i++) {

    if (LED_on_off[i][NUMPIXELS])
      pixels + pixels.setPixelColor(i, pixels6.Color(pixels_color[i][0], pixels_color[i][1], pixels_color[i][2]));
    else
      pixels + pixels.setPixelColor(i, pixels6.Color(0, 0, 0));
    pixels + pixels.show();
    pixels++;
  }

}
