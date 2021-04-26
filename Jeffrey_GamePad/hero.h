#include "Game_Pad_Character_Mask.h"
#include "Game_Pad_Character_PIX.h"
#include "Sword_Fire_MASK.h"
#include "Sword_Fire_PIX.h"

//floats for hero position and movment speed
float heroX, heroY, heroSpeed;
float swordX, swordY, swordW, swordH;
//booleans
boolean isLevelDrawn, heroDir;
int heroFrame, heroW, heroH, curTileX, curTileY, curTile;

//timer for animation speed
Metro heroFrameTimer = Metro(250);

//initializes hero values
void initHero() {
  heroX = (screenW / 2) - 12;
  heroY = (screenH / 2) - 12;
  heroSpeed = 0.4;
  isLevelDrawn = false;
  heroDir = true;
  heroFrame = 0;
  heroW = 24;
  heroH = 24;
  swordW = 16;
  swordH = 16;
}

void drawHero() {
  //NextX and NextY are set to what what the player would move too
  float nextX = heroX + (float(joystickBuffer[1]) * heroSpeed);
  float nextY = heroY + (float(joystickBuffer[0]) * heroSpeed);

  curTileX = heroX / tileSize;
  curTileY = heroY / tileSize; 
  curTile = curTileX + (curTileY * tileW);

  //if the player can move there, then the heros position will update
  if(checkMove(curMode, nextX, nextY, heroW, heroH)==true) {
    heroX = nextX;
    heroY = nextY;
  }

  if(heroX <= 20) {heroX = 22;}
  if(heroX + heroW >= 300) {heroX = 298-heroW;}
  if(heroY <= 20) {heroY = 22;}
  if(heroY + heroH >= 180) {heroY = 178-heroH;}

  //determines the value of the direction boolean
  //True = right, False = left
  if (joystickBuffer[1] == 1) {heroDir = true;}
  else if (joystickBuffer[1] == -1) {heroDir = false;}

  //if hero hasnt moved, sets the frame based off which direction he was moving
  if (joystickBuffer[1] == 0 && heroDir == true) {heroFrame = 0;}
  if (joystickBuffer[1] == 0 && heroDir == false) {heroFrame = 4;}

  //animate the hero based off which direction he is moving
  //True = right, False = left
  if (joystickBuffer[1] == 1 && heroDir == true) {
    if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 3;
      heroFrame = heroFrame + 1;
    }
  }
  if (joystickBuffer[1] == -1 && heroDir == false) {
    if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 7;
      if (heroFrame < 5) {heroFrame = 5;}
    }
  }

  //animate the hero to shield when button 1 is pressed
  if (buttonBuffer[1] == 1 && heroDir == true && shieldBool == true) {heroFrame = 8;}
  if (buttonBuffer[1] == 1 && heroDir == false && shieldBool == true) {heroFrame = 9;}

  if(buttonBuffer[0] == 1 && swordBool == true) {
    if(joystickBuffer[1] == 1) {
      swordX = heroX + heroW;
      swordY = heroY + 8;
      tft.setClipRect(swordX - 5, swordY - 5, swordW + 6, swordH + 6);
      tft.drawRGBBitmap(swordX, swordY, Sword_Fire_PIX[3], Sword_Fire_MASK[3], swordW, swordH);
      tft.updateScreen();
    } else if(joystickBuffer[1] == -1) {
        swordX = heroX - swordW;
        swordY = heroY + 8;
        tft.setClipRect(swordX - 5, swordY - 5, swordW + 6, swordH + 6);
        tft.drawRGBBitmap(swordX, swordY, Sword_Fire_PIX[1], Sword_Fire_MASK[1], swordW, swordH);
        tft.updateScreen();
      } else if (joystickBuffer[0] == -1) {
           swordX = heroX +8;
           swordY = heroY-heroH;
           tft.setClipRect(swordX - 10, swordY - 10, swordW + 6, swordH + 6);
           tft.drawRGBBitmap(swordX, swordY, Sword_Fire_PIX[0], Sword_Fire_MASK[0], swordW, swordH);
           tft.updateScreen();
        } else if (joystickBuffer[0] == 1) {
            swordX = heroX +8;
            swordY = heroY + heroH;
            tft.setClipRect(swordX - 10, swordY - 10, swordW + 6, swordH + 6);
            tft.drawRGBBitmap(swordX, swordY, Sword_Fire_PIX[2], Sword_Fire_MASK[2], swordW, swordH);
            tft.updateScreen();
          }else if (joystickBuffer[1] == 0 && heroDir == true){
              swordX = heroX + heroW;
              swordY = heroY + 8;
              tft.setClipRect(swordX - 10, swordY - 10, swordW + 6, swordH + 6);
              tft.drawRGBBitmap(swordX, swordY, Sword_Fire_PIX[3], Sword_Fire_MASK[3], swordW, swordH);
              tft.updateScreen();
            } else if (joystickBuffer[1] == 0 && heroDir == false){
                swordX = heroX - swordW;
                swordY = heroY + 8;
                tft.setClipRect(swordX - 10, swordY - 10, swordW + 6, swordH + 6);
                tft.drawRGBBitmap(swordX, swordY, Sword_Fire_PIX[1], Sword_Fire_MASK[1], swordW, swordH);
                tft.updateScreen();
              }
    swordX = 0;
    swordY=0;
  }
  
  //set a clip rectangle around the hero and update when he moves
  tft.setClipRect(heroX - 3, heroY - 3, heroW + 6, heroH + 6);
  tft.drawRGBBitmap(heroX, heroY, Game_Pad_Character_PIX[heroFrame], Game_Pad_Character_MASK[heroFrame], heroW, heroH);
  tft.updateScreen();

}
