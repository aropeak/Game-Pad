// The Legend of Chad
// Jeffrey Stephens || 29 March 2021
// CRT 360 Advanced Prototyping || GamePad

#include "frame.h"
#include "screen.h"
#include "tile.h"

int tileChange = 0;
Metro tiles = Metro(1000);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initScreen();



}

void loop() {
  // put your main code here, to run repeatedly:

  checkFrame();
  Serial.println(fps);

  if (tiles.check()) {
    tileChange = (tileChange + 1) % 8;
  }

  //screenTest(change);
  drawLevel(tileChange);
  tft.updateScreen();

}
