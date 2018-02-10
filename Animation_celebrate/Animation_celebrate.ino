#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "Celebrate.h"

const int PIN = 7;
const int NUM_PIXELS = 8;
const int BRIGHTNESS = 160;
PixelStrip *strip = new PixelStrip(NUM_PIXELS, PIN, NEO_GRB);
Celebrate *animation;
void setup() {
  animation = new Celebrate();
  strip->setup();
  strip->setBrightness(BRIGHTNESS);
  strip->setAnimation(animation);
}
void loop() {
  strip->draw();
  strip->show();
  delay(10);
}
