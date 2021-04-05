// The Legend of Chad
// Jeffrey Stephens || 29 March 2021
// CRT 360 Advanced Prototyping || GamePad

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "hero.h"

void setup() {

  Serial.begin(9600);
  initScreen();
  initControls();
  initHero();

}


void loop() {

  //checkFrame();
  //Serial.println(fps);
  //screenTest(change);

  getControls();
  drawHero();

}
