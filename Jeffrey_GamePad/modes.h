#include "introGraphic_PIX.h"
#include "introGraphic_MASK.h"

//sets global variables
int initIntro;
boolean lvl1, lvl2, lvl3, lvl4, lvl5, lvl6, lvl7, lvl8;

//initializes global variables
void initModes() {
  initIntro = false;
  lvl1 = false;
  lvl2 = false;
  lvl3 = false;
  lvl4 = false;
  lvl5 = false;
  lvl6 = false;
  lvl7 = false;
  lvl8 = false;
}

//draws title screen
void introScreen() {
  //if screen hasnt been drawn, draw screen
  if (initIntro == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, introGraphic_PIX[0], 320, 240);
    tft.updateScreen();
    initIntro = true;
  }
  //if button 2 has been pressed, then move to room 1
  if (buttonBuffer[2] == 1) {curMode = 0;}
}
//draws the first room
void firstLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl1 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    tft.updateScreen();
    lvl1 = true;
  }
  //draw the player
  drawLevel(0);
  drawHero();
  
  if (buttonBuffer[3] == 1) {curMode = 1;}
}
//draws the second room
void secondLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl2 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(1);
    tft.updateScreen();
    lvl2 = true;
  }
  //draw the player
  drawLevel(1);
  drawHero();
  
  if (buttonBuffer[2] == 1) {curMode = 2;}
}
//draws the third room
void thirdLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl3 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(2);
    tft.updateScreen();
    lvl3 = true;
  }
  //draw the player
  drawLevel(2);
  drawHero();
  
  if (buttonBuffer[3] == 1) {curMode = 3;}
}
//draws the fourth room
void fourthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl4 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(3);
    tft.updateScreen();
    lvl4 = true;
  }
  //draw the player
  drawLevel(3);
  drawHero();
  
  if (buttonBuffer[2] == 1) {curMode = 4;}
}
//draws the fifth room
void fifthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl5 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(4);
    tft.updateScreen();
    lvl5 = true;
  }
  //draw the player
  drawLevel(4);
  drawHero();
  
  if (buttonBuffer[3] == 1) {curMode = 5;}
}
//draws the sixth room
void sixthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl6 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(5);
    tft.updateScreen();
    lvl6 = true;
  }
  //draw the player
  drawLevel(5);
  drawHero();
  
  if (buttonBuffer[2] == 1) {curMode = 6;}
}
//draws the seventh room
void seventhLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl7 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(6);
    tft.updateScreen();
    lvl7 = true;
  }
  //draw the player
  drawLevel(6);
  drawHero();
  
  if (buttonBuffer[3] == 1) {curMode = 7;}
}
//draws the boss room
void eigthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl8 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(7);
    tft.updateScreen();
    lvl8 = true;
  }
  //draw the player
  drawLevel(7);
  drawHero();
}
//cases to setup each level
void runMode() {
  switch (curMode) {
    case -1: introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: sixthLevel(); break;
    case 6: seventhLevel(); break;
    case 7: eigthLevel(); break;
  }
}
