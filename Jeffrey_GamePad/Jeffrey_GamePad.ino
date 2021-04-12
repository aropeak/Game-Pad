// The Legend of Chad
// Jeffrey Stephens || 29 March 2021
// CRT 360 Advanced Prototyping || GamePad

int curMode = -1;

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "status.h"
#include "interaction.h"
#include "hero.h"
#include "modes.h"


Metro test = Metro(2000);

void setup() {
    initLevel();

  Serial.begin(9600);
  initScreen();
  initControls();
  initHero();
  initNeighbors();
  initStatus();

}


void loop() {

  getControls();
  //drawHero();
  runMode();
 // checkFrame();
  tft.updateScreen();

//  Serial.print(heroX);
//  Serial.print("  |  ");
//  Serial.println(heroY);

  if(heroHealth == 0) {
    curMode = 8;
  }

}
