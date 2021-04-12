#include "introGraphic_PIX.h"
#include "introGraphic_MASK.h"

//sets global variables
int initIntro, initDied;
boolean lvl1, lvl2, lvl3, lvl4, lvl5, lvl6, lvl7, lvl8;

//initializes global variables
void initModes() {
  initIntro = false;
  initDied = false;
  lvl1 = false; lvl2 = false; lvl3 = false; lvl4 = false;
  lvl5 = false; lvl6 = false; lvl7 = false; lvl8 = false;
}

//draws title screen
void introScreen() {
  //if screen hasnt been drawn, draw screen
  if (initIntro == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, introGraphic_PIX[0], 320, 240);
    tft.updateScreen();
    initIntro = true;
    initDied = false;

    heroX = screenW/2;
    heroY = screenH/2;
  }
  //if button 2 has been pressed, then move to room 1
  if (buttonBuffer[2] == 1) {curMode = 0; initIntro = false;}
}
//draws the first room
void firstLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl1 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(0);
    tft.updateScreen();
    lvl1 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateKey();
    updateHealth();
  }

  //draw the player
  drawLevel(0);
  drawHero();
  
  if(interaction[curMode][curTile] == 0x02 && buttons[2].rose()){curMode = 1; lvl1 = false; heroX = 150; heroY = 160;}
  if(interaction[curMode][curTile] == 0x09 && buttons[2].rose()){swordBool = true; chest1 = true; updateSword();}

}
//draws the second room
void secondLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl2 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(1);
    tft.updateScreen();
    lvl2 = true;
    updateHead(0);
    updateSword(); 
    updateShield();
    updateKey();
    updateHealth();
  }
  //draw the player
  drawLevel(1);
  drawHero();

  if(interaction[curMode][curTile] == 0x01 && buttons[2].rose()){curMode = 0; lvl2 = false; heroX = 150; heroY = 10;}
  if(interaction[curMode][curTile] == 0x03 && buttons[2].rose()){curMode = 2; lvl2 = false; heroX = 290; heroY = 85;}
  if(interaction[curMode][curTile] == 0x05 && buttons[2].rose()){curMode = 4; lvl2 = false; heroX = 10; heroY = 85;}
 
}
//draws the third room
void thirdLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl3 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(2);
    tft.updateScreen();
    lvl3 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateHealth();
    updateKey();
    updateHealth1();
  }
  //draw the player
  drawLevel(2);
  drawHero();

  if(interaction[curMode][curTile] == 0x04 && buttons[2].rose()){curMode = 3; lvl3 = false; heroX = 150; heroY = 160;}
  if(interaction[curMode][curTile] == 0x02 && buttons[2].rose()){curMode = 1; lvl3 = false; heroX = 10; heroY = 85;}
  if(interaction[curMode][curTile] == 0x0A){heroHealth = 0;}
  if(interaction[curMode][curTile] == 0x09 && buttons[2].rose()){healthBool1 = true; chest4 = true; updateHealth1(); updateHealth();}
}
//draws the fourth room
void fourthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl4 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(3);
    tft.updateScreen();
    lvl4 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateHealth();
    updateKey();
  }
  //draw the player
  drawLevel(3);
  drawHero();

  if(interaction[curMode][curTile] == 0x03 && buttons[2].rose()){curMode = 2; lvl4 = false; heroX = 150; heroY = 10;}
  if(interaction[curMode][curTile] == 0x07 && buttons[2].rose()){curMode = 6; lvl4 = false; heroX = 10; heroY = 85;}
  if(interaction[curMode][curTile] == 0x0A){heroHealth = 0;}
  if(interaction[curMode][curTile] == 0x09 && buttons[2].rose()){keyBool = true; chest5 = true; updateKey();}
}
//draws the fifth room
void fifthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl5 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(4);
    tft.updateScreen();
    lvl5 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateKey();
    updateHealth();
  }
  //draw the player
  drawLevel(4);
  drawHero();

  if(interaction[curMode][curTile] == 0x02 && buttons[2].rose()){curMode = 1; lvl5 = false; heroX = 290; heroY = 85;}
  if(interaction[curMode][curTile] == 0x06 && buttons[2].rose()){curMode = 5; lvl5 = false; heroX = 150; heroY = 160;}
  if(interaction[curMode][curTile] == 0x0A){heroHealth = 0;}
  if(interaction[curMode][curTile] == 0x09 && buttons[2].rose()){shieldBool = true; chest2 = true; updateShield();}
  
}
//draws the sixth room
void sixthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl6 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(5);
    tft.updateScreen();
    lvl6 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateKey();
    updateHealth();
    updateHealth1();
  }
  //draw the player
  drawLevel(5);
  drawHero();

  if(interaction[curMode][curTile] == 0x05 && buttons[2].rose()){curMode = 4; lvl6 = false; heroX = 150; heroY = 10;}
  if(interaction[curMode][curTile] == 0x07 && buttons[2].rose()){curMode = 6; lvl6 = false; heroX = 290; heroY = 85;}
  if(interaction[curMode][curTile] == 0x0A){heroHealth = 0;}
  if(interaction[curMode][curTile] == 0x09 && buttons[2].rose()){healthBool1 = true; chest3 = true; updateHealth1(); updateHealth();}
}
//draws the seventh room
void seventhLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl7 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(6);
    tft.updateScreen();
    lvl7 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateKey();
    updateHealth();
  }
  //draw the player
  drawLevel(6);
  drawHero();

  if(interaction[curMode][curTile] == 0x04 && buttons[2].rose()){curMode = 3; lvl7 = false; heroX = 290; heroY = 85;}
  if(interaction[curMode][curTile] == 0x06 && buttons[2].rose()){curMode = 5; lvl7 = false; heroX = 10; heroY = 85;}
  if(interaction[curMode][curTile] == 0x08 && buttons[2].rose()){curMode = 7; lvl7 = false; heroX = 150; heroY = 160;}

}
//draws the boss room
void eigthLevel() {
  //if screen hasnt been drawn, draw screen
  if (lvl8 == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    drawLevel(7);
    tft.updateScreen();
    lvl8 = true;
    updateHead(0);
    updateSword();
    updateShield();
    updateKey();
    updateHealth();
  }
  //draw the player
  drawLevel(7);
  drawHero();

  if(interaction[curMode][curTile] == 0x07 && buttons[2].rose()){curMode = 6; lvl8 = false; heroX = 150; heroY = 10;}
  if(interaction[curMode][curTile] == 0x0A){heroHealth = 0;}
}

void youDied(){
  //if screen hasnt been drawn, draw screen
  if (initDied == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.drawRGBBitmap(0, 0, introGraphic_PIX[1], 320, 240);
    tft.updateScreen();
    initIntro = true;
  }
  if(buttons[2].rose()) {curMode = -1; initDied = false;   
    initScreen();
    initControls();
    initHero();
    initNeighbors();
    initStatus();
  }
  Serial.println(curMode);
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
    case 8: youDied(); break;
  }
}
