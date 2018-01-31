#include <Adafruit_NeoPixel.h>
#include "PacmanAnimation.h"

int pixelState = 0;

void PacmanAnimation::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
  currentPixel = 0;
}

void PacmanAnimation::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->clear();
    for (int i = strip->numPixels() - 1; i > currentPixel; i = i - 3) {
      strip->setPixelColor(i, 0xFFFFFF);
    }

    strip->setPixelColor(currentPixel, 0xFFFF00);
    currentPixel = currentPixel + 1;
    if (currentPixel > strip-> numPixels() - 1) currentPixel = 0;
    setTimeout(waitTime);

  }
}
