// The Legend of Chad
// Jeffrey Stephens || 29 March 2021
// CRT 360 Advanced Prototyping || GamePad

int curMode = -1;

#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "interaction.h"
#include "hero.h"
#include "modes.h"


Metro test = Metro(2000);

void setup() {

  Serial.begin(9600);
  initScreen();
  initControls();
  initHero();
  initNeighbors();

}


void loop() {

  getControls();
  //drawHero();
  runMode();
  checkFrame();
  tft.updateScreen();

//  Serial.print(neighbors[88][0]);
//  Serial.print("  |  ");
//  Serial.print(neighbors[88][1]);
//  Serial.print("  |  ");
//  Serial.print(neighbors[88][2]);
//  Serial.print("  |  ");
//  Serial.print(neighbors[88][3]);
//  Serial.print("  |  ");
//  Serial.println(neighbors[88][4]);
 
}
