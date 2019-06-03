
// press the button it will change to a new pixel animation.  Note that you need to press the
// button once to start the first animation!

#include <Adafruit_NeoPixel.h>

#define PIXEL_LENGTH 9

int brightnessVal = 255;

// for Pixel Light
const uint16_t pixelCountArr[PIXEL_LENGTH] = {120, 120, 120, 120};
const uint8_t pixelPinArr[PIXEL_LENGTH] = {8, 9, 10, 11};
Adafruit_NeoPixel stripArr[PIXEL_LENGTH];

// for Button
bool oldState[PIXEL_LENGTH] = {HIGH, HIGH, HIGH, HIGH};
const uint8_t btnPinArr[PIXEL_LENGTH] = {A5, A4, A3, A2};

//bool waitUnity = false; //for Unity

void setup() {
  Serial.begin(9600);

  InitButton();
  InitPixel();
}

void loop() {
  CheckUnity();
  CheckReset();

  CheckButton();
}

void CheckUnity() {
  if (Serial.available() > 0 && Serial.readString() == "99") {
    ResetPixel();
  }
}

void CheckReset() {
  if (Serial.available() > 0 && Serial.readString() == "90") {
    ResetPixel();
  }
}

void ResetPixel() {
  for (unsigned int i = 0; i < PIXEL_LENGTH; i++) {
    ReloadColor(stripArr[i], stripArr[i].Color(0, 0, 0));
  }
}

void InitPixel() {
  for (unsigned int i = 0; i < PIXEL_LENGTH; i++) {
    stripArr[i] = Adafruit_NeoPixel(pixelCountArr[i], pixelPinArr[i], NEO_GRB + NEO_KHZ800);
    stripArr[i].begin();
    stripArr[i].show(); // Initialize all pixels to 'off'
  }
}

void InitButton() {
  for (unsigned int i = 0; i < PIXEL_LENGTH; i++) {
    pinMode(btnPinArr[i], INPUT_PULLUP);
  }
}

void CheckButton() {
  for (unsigned int i = 0; i < PIXEL_LENGTH; i++) {
    // Get current button state.

    if ( digitalRead(btnPinArr[i] == 1 ) {
    // Short delay to debounce button.

    ResetPixel();

      LoadColor(stripArr[i], stripArr[i].Color(brightnessVal, brightnessVal, brightnessVal));

      Serial.println(i);
      return;


      bool newState = digitalRead(btnPinArr[i]);

      // Check if state changed from high to low (button press).
      if (newState == LOW && oldState[i] == HIGH) {
        // Short delay to debounce button.
        delay(20);
        // Check if button is still low after debounce.
        newState = digitalRead(btnPinArr[i]);
        if (newState == LOW) {
          ResetPixel();

          LoadColor(stripArr[i], stripArr[i].Color(brightnessVal, brightnessVal, brightnessVal));

          Serial.println(i);
          return;
        }
      }

      // Set the last button state to the old state.
      oldState[i] = newState;

    }
  }

  void LoadColor(Adafruit_NeoPixel & strip, uint32_t c) {
    for (uint16_t i = strip.numPixels() - 1; i > 0; i--) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(5);
    }
  }

  void ReloadColor(Adafruit_NeoPixel & strip, uint32_t c) {
    for (uint16_t i = strip.numPixels() - 1; i > 0; i--) {
      strip.setPixelColor(i, c);
    }
    strip.show();
  }
