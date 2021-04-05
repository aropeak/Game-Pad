#include "Game_Pad_Character_Mask.h"
#include "Game_Pad_Character_PIX.h"

//floats for hero position and movment speed
float heroX, heroY, heroSpeed;

//booleans
boolean isLevelDrawn, heroDir;
int heroFrame;

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
}

void drawHero() {
  //moves the hero based off the joystick inputs
  heroX = heroX + (joystickBuffer[1] * heroSpeed);
  heroY = heroY + (joystickBuffer[0] * heroSpeed);

  //sets boundaries for the hero
  if ((heroX + 24) > 300) {
    heroX = 300 - 24;
  } else if (heroX < 20) {
    heroX = 20;
  }
  if ((heroY + 24) > 180) {
    heroY = 180 - 24;
  } else if (heroY < 20) {
    heroY = 20;
  }

  //determines the value of the direction boolean
  //True = right, False = left
  if (joystickBuffer[1] == 1) {
    heroDir = true;
  } else if (joystickBuffer[1] == -1) {
    heroDir = false;
  }

  //if hero hasnt moved, sets the frame based off which direction he was moving
  if (joystickBuffer[1] == 0 && heroDir == true) {
    heroFrame = 0;
  }
  if (joystickBuffer[1] == 0 && heroDir == false) {
    heroFrame = 4;
  }

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
      if (heroFrame < 5) {
        heroFrame = 5;
      }
    }
  }

  //animate the hero to shield when button 1 is pressed
  if (buttonBuffer[1] == 1 && heroDir == true) {
    heroFrame = 8;
  }
  if (buttonBuffer[1] == 1 && heroDir == false) {
    heroFrame = 9;
  }

  //draw the level
  drawLevel(0);

  //update the entire screen if the level hasnt been drawn
  if (isLevelDrawn == false) {
    tft.updateScreen();
    isLevelDrawn = true;
  }
  //set a clip rectangle around the hero and update when he moves
  tft.setClipRect(heroX - 3, heroY - 3, 30, 30);
  tft.drawRGBBitmap(heroX, heroY, Game_Pad_Character_PIX[heroFrame], Game_Pad_Character_MASK[heroFrame], 24, 24);
  tft.updateScreen();

}
