#ifndef PacmanAnimation_h
#define PacmanAnimation_h
#include <Animation.h>

/**

*/
class PacmanAnimation : public Animation {
  public:
    PacmanAnimation();
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 500;
    int currentPixel = 0;
  private:
};
#endif
