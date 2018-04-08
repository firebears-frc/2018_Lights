#include <AdaFruit_NeoPixel.h>

#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include <Wire.h>
#include "BuildUp.h"
#include "Celebrate.h"
#include "FadeAnimation.h"
#include "FireAnimation.h"
#include "FlashFall.h"
#include "NullZone.h"
#include "PacmanAnimation.h"

const int MAX_ANIMATIONS = 9;
const int MAX_PIXELSTRIPS = 3;
const int BRIGHTNESS = 60;
const int I2C_ADDRESS = 4;
const int BUILD_ANIMATION = 0;
const int CELEBRATE_ANIMATION = 1;
const int CUBE_ANIMATION = 2;
const int FIRE_ANIMATION = 3;
const int FALL_ANIMATION = 4;
const int NULL_ANIMATION = 5;
const int PACMAN_ANIMATION = 6;
const int BLUE_ANIMATION = 7;
const int RED_ANIMATION = 8;

const int SHOOTER_STRIP = 0;
const int GRABBER_STRIP = 1;
const int BASE_STRIP = 2;


PixelStrip *strip[MAX_PIXELSTRIPS];
Animation *animation[MAX_ANIMATIONS];
int wireTimeout = 0;

/**
   Change animations when I2C messages are received.
*/
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // set up all Animations
  animation[BUILD_ANIMATION] = new BuildUp();
  animation[CELEBRATE_ANIMATION] = new Celebrate();
  animation[CUBE_ANIMATION] = new FadeAnimation();
  ((FadeAnimation*)animation[CUBE_ANIMATION])->setColor (0, 0x174702);
  ((FadeAnimation*)animation[CUBE_ANIMATION])->setColor (1, 0x2E9800);
  animation[FIRE_ANIMATION] = new FireAnimation();
  animation[FALL_ANIMATION] = new FlashFall();
  animation[NULL_ANIMATION] = new NullZone();
  animation[PACMAN_ANIMATION] = new PacmanAnimation();
  animation[BLUE_ANIMATION] = new FadeAnimation();
  ((FadeAnimation*)animation[BLUE_ANIMATION])->setColor (0, 0x4F009E);
  ((FadeAnimation*)animation[BLUE_ANIMATION])->setColor (1, 0x10009E);
  animation[RED_ANIMATION] = new FadeAnimation();
  ((FadeAnimation*)animation[RED_ANIMATION])->setColor (0, 0xFF0000);
  ((FadeAnimation*)animation[RED_ANIMATION])->setColor (1, 0x9E0000);
  // set up all PixelStrips
  strip[SHOOTER_STRIP] = new PixelStrip(78, 1, NEO_GRB);
  strip[GRABBER_STRIP] = new PixelStrip(24, 3, NEO_GRB);
  strip[BASE_STRIP] = new PixelStrip(121, 4, NEO_GRB);
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->setup();
    strip[s]->setAnimation(animation[FIRE_ANIMATION]);
    strip[s]->setBrightness(BRIGHTNESS);
  }
}

void loop() {
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->draw();
    strip[s]->show();
  }
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

/**
   Expects to receive two characters.
   The first character specifies the pixel strip number.
   The second character sets the animation number on that strip.
*/
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int s = Wire.read() - '0';
    int a = Wire.read() - '0';
    if (a >= 0 && a < MAX_ANIMATIONS) {
      strip[s]->setAnimation(animation[a]);
    } else {
      strip[s]->setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
  }
}
