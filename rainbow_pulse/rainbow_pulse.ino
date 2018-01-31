#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include "PulseAnimation.h"

const int PINa = 1;
const int PINb = 4;

const int NUM_PIXELS = 8;
const int BRIGHTNESS = 128;

PixelStrip *stripa = new PixelStrip(NUM_PIXELS, PINa, NEO_GRB);
PixelStrip *stripb = new PixelStrip(NUM_PIXELS, PINb, NEO_GRB);
PulseAnimation *animation;

void setup() {
  animation = new PulseAnimation();
  stripa->setup();
  stripb->setup();
  stripa->setBrightness(BRIGHTNESS);
  stripb->setBrightness(BRIGHTNESS);
  stripa->setAnimation(animation);
  stripb->setAnimation(animation);
}

void loop() {
  stripa->draw();
  stripb->draw();
  stripa->show();
  stripb->show();
  delay(10);
}
