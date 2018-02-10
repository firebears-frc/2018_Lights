#ifndef Celebrate_h
#define Celebrate_h
#include <Animation.h>

/**
 *
 */
class Celebrate : public Animation {
  public:
    Celebrate();
    Celebrate(int n);
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    void setColor(int i, uint32_t c);


    /** Milliseconds for each pulse cycle.  */
    unsigned long timeCycle = 2000;


  private:
    int f(unsigned long t);
    uint32_t fadeColor(uint32_t c, int brightness);
    uint32_t *colorList;
    int colorCount;
};
#endif
