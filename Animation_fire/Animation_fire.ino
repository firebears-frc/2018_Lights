#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "FireAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 250;

PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
FireAnimation *animation;

void setup() {
  animation = new FireAnimation();
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
