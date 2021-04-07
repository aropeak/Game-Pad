#include "Game_Pad_Character_Mask.h"
#include "Game_Pad_Character_PIX.h"

//floats for hero position and movment speed
float heroX, heroY, heroSpeed;

//booleans
boolean isLevelDrawn, heroDir;
int heroFrame, heroW, heroH;

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
}

void drawHero() {
  //NextX and NextY are set to what what the player would move too
  float nextX = heroX + (float(joystickBuffer[1]) * heroSpeed);
  float nextY = heroY + (float(joystickBuffer[0]) * heroSpeed);

  //if the player can move there, then the heros position will update
  if(checkMove(curMode, nextX, nextY, heroW, heroH)==true) {
    heroX = nextX;
    heroY = nextY;
  }

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
  if (buttonBuffer[1] == 1 && heroDir == true) {heroFrame = 8;}
  if (buttonBuffer[1] == 1 && heroDir == false) {heroFrame = 9;}

  //set a clip rectangle around the hero and update when he moves
  tft.setClipRect(heroX - 3, heroY - 3, heroW + 6, heroH + 6);
  tft.drawRGBBitmap(heroX, heroY, Game_Pad_Character_PIX[heroFrame], Game_Pad_Character_MASK[heroFrame], heroW, heroH);
  tft.updateScreen();

}
