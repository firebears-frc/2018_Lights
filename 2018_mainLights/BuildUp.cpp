#include <Adafruit_NeoPixel.h>
#include "BuildUp.h"

void BuildUp::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  strip->clear();
  strip->show();
  setTimeout(1000);
  currentPixel = 0;

}

void BuildUp::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(currentPixel, 0x174702);
    currentPixel = currentPixel + 1;
    setTimeout(waitTime);
  }
}

