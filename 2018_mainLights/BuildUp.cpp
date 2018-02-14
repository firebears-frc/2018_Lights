#include <Adafruit_NeoPixel.h>
#include "BuildUp.h"
BuildUp::BuildUp() {
  strip->clear();
  strip->show();
  setTimeout(1000);
  currentPixel = 0;
}

void BuildUp::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  
}

void BuildUp::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    strip->setPixelColor(currentPixel, 0x174702);
    currentPixel = currentPixel + 1;
    setTimeout(waitTime);
  }
}

