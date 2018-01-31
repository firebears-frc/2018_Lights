#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "PacmanAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 67;

PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
PacmanAnimation *animation;

void setup() {
  animation = new PacmanAnimation();
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
