#ifndef BuildUp_h
#define BuildUp_h
#include <Animation.h>

/**

*/
class BuildUp : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    int currentPixel = 0;
    unsigned long waitTime = 250;
    unsigned long color = 0x008800;
  private:
};
#endif
