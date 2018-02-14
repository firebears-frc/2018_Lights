#ifndef FlashFall_h
#define FlashFall_h
#include <Animation.h>

/**

*/
class FlashFall : public Animation {
  public:
  FlashFall();
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    int currentPixel = 7;
    int state = 0;
    unsigned long waitTime = 1000;
    unsigned long color = 0x008800;
  private:
};
#endif
