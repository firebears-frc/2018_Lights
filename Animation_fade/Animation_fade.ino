#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "FadeAnimation.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
FadeAnimation *animation;

void setup() {
  animation = new FadeAnimation();
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
}

void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
