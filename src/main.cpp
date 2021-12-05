#include <Adafruit_NeoPixel.h>
#define BUTTON      3
#define LED         2
#define NUMPIXELS   1

Adafruit_NeoPixel pixels(NUMPIXELS, LED, NEO_GRB + NEO_KHZ800);

int lastState = HIGH;
int currentState;  

int buttonCount = 1;

void setup() {
  Serial.begin(115200);
  pixels.begin();
  pinMode(BUTTON, INPUT_PULLUP);
}

int high = 255;
int mid = 128;
int low = 0;

void setLed() {
  pixels.clear();
  switch (buttonCount) {
    case 1:
      pixels.setPixelColor(0, pixels.Color(high, low, low));
      break;
    case 2:
      pixels.setPixelColor(0, pixels.Color(high, mid, mid));
      break;
    case 3:
      pixels.setPixelColor(0, pixels.Color(low, high, low));
      break;
    case 4:
      pixels.setPixelColor(0, pixels.Color(mid, high, mid));
      break;
    case 5:
      pixels.setPixelColor(0, pixels.Color(low, low, high));
      break;
    case 6:
      pixels.setPixelColor(0, pixels.Color(mid, mid, high));
      break;
    default:
      break;
  }
  pixels.show();
}

void loop() {
  currentState = digitalRead(BUTTON);
  if(lastState == LOW && currentState == HIGH) {
    Serial.println("Button Pressed!");
    buttonCount++;
    if (buttonCount > 6) {
      buttonCount = 1;
    }
    setLed();
  }
  lastState = currentState;
}
