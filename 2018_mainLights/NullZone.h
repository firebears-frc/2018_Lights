#ifndef NullZone_h
#define NullZone_h
#include <Animation.h>

/**

*/
class NullZone : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    unsigned long waitTime = 1500;
    unsigned long color = 0x008800;
    boolean lightOn = false;
  private:
};
#endif
