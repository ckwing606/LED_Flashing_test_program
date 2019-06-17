#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        8 // On Trinket or Gemma, suggest changing this to 1
#define PIN2       9
#define PIN3       10

// How many NeoPixels are attached to the Arduino?

#define NUMPIXELS 57 // Popular NeoPixel ring size
int LED_on_off_1[NUMPIXELS] = {1, 0, 0, 0, 1};
int LED_on_off_2[NUMPIXELS] = {0, 1, 0, 1, 0};
int LED_on_off_3[NUMPIXELS] = {0, 0, 1, 0, 0};

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 80 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin();
  pixels3.begin();
  pixels.clear(); // Set all pixel colors to 'off'
  pixels2.clear();
  pixels3.clear();
  pixels.show();
  pixels2.show();
  pixels3.show();

  Serial.begin(9600);


  /*for ( int x = 0; x <= NUMPIXELS; x++) {

    if ( x % 4 == 0 ) {
      LED_on_off_1[x] = 1;
    } else {
      LED_on_off_1[x] = 0;
    }


    if ( (x + 1) % 2 == 0 ) {
      LED_on_off_2[x] = 1;
    } else {
      LED_on_off_2[x] = 0;
    }


    if ( (x + 2) % 4 == 0 ) {
      LED_on_off_3[x] = 1;
    } else {
      LED_on_off_3[x] = 0;
    }
  }
  Serial.println("Setting up LED Strip 1, 2, 3:");

  for (int i = 0 ; i < NUMPIXELS; i++) {
    //Array value checker
    Serial.println(LED_on_off_1[i]);
  }
  delay(100);
*/
}

void loop() {

  Serial.println(LED_on_off_1[5]);



  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.

  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

//    Checking index of i
//    Serial.println(i);

//    if ( i % q == 0 ) {

      pixels.clear(); // Set all pixel colors to 'off'
      pixels2.clear();
      pixels3.clear();

    //}


    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:

    if (LED_on_off_1[i])
      pixels.setPixelColor(i, pixels.Color(0, 15, 60));
    else
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    if (LED_on_off_2[i])
      pixels2.setPixelColor(i, pixels2.Color(0, 15, 60));
    else
      pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
    pixels2.show();
    if (LED_on_off_3[i])
      pixels3.setPixelColor(i, pixels3.Color(0, 15, 60));
    else
      pixels3.setPixelColor(i, pixels3.Color(0, 0, 0));
    pixels3.show();
    delay(DELAYVAL);

  }
  /*
    for (int i = NUMPIXELS ; i >= 0 ; i--) { // For each pixel...
      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      pixels.clear(); // Set all pixel colors to 'off'
      pixels2.clear();
      if (LED_on_off_1[i])
        pixels.setPixelColor(i, pixels.Color(40, 0, 50));
      else
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels.show();   // Send the updated pixel colors to the hardware.
      if (LED_on_off_2[i])
        pixels2.setPixelColor(i, pixels.Color(0, 15, 60));
      else
        pixels2.setPixelColor(i, pixels.Color(0, 0, 0));
      pixels2.show();
      delay(DELAYVAL);
    }
  */
}
