#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include <Wire.h>
#include "BuildUp.h"
#include "Celebrate.h"
#include "FadeAnimation.h"
#include "FireAnimation.h"
#include "FlashFall.h"
#include "NullZone.h"
#include "PacmanAnimation.h"

const int MAX_ANIMATIONS = 7;
const int MAX_PIXELSTRIPS = 1;
const int BRIGHTNESS = 128;
const int I2C_ADDRESS = 4;

PixelStrip *strip[MAX_PIXELSTRIPS];
Animation *animation[MAX_ANIMATIONS];
int wireTimeout = 0;

/**
   Change animations when I2C messages are received.
*/
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // set up all Animations
  animation[0] = new BuildUp();
  animation[1] = new Celebrate();
  animation[2] = new FadeAnimation();
  animation[3] = new FireAnimation();
  animation[4] = new FlashFall();
  animation[5] = new NullZone();
  animation[6] = new PacmanAnimation();
 

  // set up all PixelStrips
  strip[0] = new PixelStrip(8, 1, NEO_GRB);
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->setup();
    strip[s]->setAnimation(animation[0]);
    strip[s]->setBrightness(BRIGHTNESS);
  }
}

void loop() {
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->draw();
    strip[s]->show();
  }
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

/**
   Expects to receive two characters.
   The first character specifies the pixel strip number.
   The second character sets the animation number on that strip.
*/
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int s = Wire.read() - '0';
    int a = Wire.read() - '0';
    if (a >= 0 && a < MAX_ANIMATIONS) {
      strip[s]->setAnimation(animation[a]);
    } else {
      strip[s]->setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
  }
}
