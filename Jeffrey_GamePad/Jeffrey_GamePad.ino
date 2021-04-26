// The Legend of Chad
// Jeffrey Stephens || 29 March 2021
// CRT 360 Advanced Prototyping || GamePad

int curMode = -2;

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "status.h"
#include "interaction.h"
#include "hero.h"
#include "enemy.h"
#include "nobert.h"
#include "fight.h"
#include "modes.h"

Metro test = Metro(2000);

void setup() {
  initLevel();
  Serial.begin(9600);
  randomSeed(analogRead(A8));
  initScreen();
  initControls();
  initHero();
  initNeighbors();
  initStatus();
  initModes();
  initEnemy();
  initNorbert();
}

void loop() {
  getControls();
  runMode();
  //checkFrame();
  tft.updateScreen();
  if(heroHealth == 0) {
    curMode = 8;
  }
}
