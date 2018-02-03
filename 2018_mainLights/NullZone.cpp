#include <Adafruit_NeoPixel.h>
#include "NullZone.h"


void NullZone::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(1);
}

void NullZone::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    if (lightOn) {
      for (int i = 0; i < strip->numPixels(); i = i + 1) {
        strip->setPixelColor(i, 0xFFFFFF);
      }
      lightOn = false;
    } else {
      strip->clear();
      lightOn = true;
    }
    setTimeout(waitTime);
  }
}
