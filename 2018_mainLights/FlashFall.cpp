#include <Adafruit_NeoPixel.h>
#include "FlashFall.h"

int pixelState = 0;

void FlashFall::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
  state = 0;
  currentPixel = strip-> numPixels() - 1;
}

void FlashFall::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    if (state == 0) {
      for (int i = 0; i < strip->numPixels(); i = i + 1) {
        strip->setPixelColor(i, 0x174702);
      }
      state = 1;
      setTimeout(200);
    } else if (state == 1) {
      for (int i = 0; i < strip->numPixels(); i = i + 1) {
        strip->setPixelColor(i, 0xFFFFFF);
      }
      state = 2;
      setTimeout(500);
    } else if (state == 2) {
      for (int i = 0; i < strip->numPixels(); i = i + 1) {
        strip->setPixelColor(i, 0x174702);
      }
      state = 3;
      setTimeout(500);
    } else {
      strip->setPixelColor(currentPixel, 0x000000);
      currentPixel = currentPixel - 1;
      setTimeout(100);
    }
  }
}



