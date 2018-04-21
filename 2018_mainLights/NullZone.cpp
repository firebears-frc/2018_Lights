#include <Adafruit_NeoPixel.h>
#include "NullZone.h"


void NullZone::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  for (int i = 0; i < strip->numPixels(); i = i + 1) {
    strip->setPixelColor(i, 0xFFFFFF);
  }
}

void NullZone::draw(Adafruit_NeoPixel *strip) {
  for (int i = 0; i < strip->numPixels(); i = i + 1) {
    strip->setPixelColor(i, 0xFFFFFF);
  }
}
