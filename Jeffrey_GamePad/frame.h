#include <Metro.h>          // This adds the Metro library to your sketch
Metro frameRate = Metro(1000); // A prototype for a Metro timer

int fps = 0;

void checkFrame() {
  if (frameRate.check( )) {
    // do something
    fps = 0;
  }
  fps = fps + 1;
}
