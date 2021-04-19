#include "Game_Pad_Enemy_PIX.h"
#include "Game_Pad_Enemy_MASK.h"

Metro enemyFrameTimer = Metro(250);
Metro enemyBrainTimer = Metro(1000);

int enemyMargin, enemyStatus, enemyHealth, enemySmart, enemyW, enemyH, enemyFrame;
float enemyX, enemyY, enemyXDir, enemyYDir, enemySpeed;
boolean enemyFire, enemyDraw;

void initEnemy() {
  enemyMargin = 2;
  //enemyStatus = 1;
  enemyHealth = 1;
  enemySmart = 3;
  enemyX = 0;
  enemyY = 0;
  enemyXDir = 0;
  enemyYDir = 0;
  enemySpeed = 0.15;
  enemyW = 32;
  enemyH = 32;
  enemyFrame = 0;
  //enemyFire = false;
}

void drawEnemy() {
  if(enemyBrainTimer.check()){
    if(random(0, (enemySmart + 1)) == 0) {
      enemyXDir = random(-1,2);
      enemyYDir = random(-1,2);
    } else {
      if(heroX < enemyX) {enemyXDir = -1;}
        else if(heroX > enemyX) {enemyXDir = 1;}
        else {enemyXDir = 0;}
      if(heroY < enemyY) {enemyYDir = -1;}
        else if(heroY > enemyY) {enemyYDir = 1;}
        else {enemyYDir = 0;}
    }
  }

  float nextEX = enemyX + (enemyXDir * enemySpeed);
  float nextEY = enemyY + (enemyYDir * enemySpeed);

  if(checkMove(curMode, nextEX, nextEY, enemyW, enemyH)==true && checkMove2(curMode, nextEX, nextEY, enemyW, enemyH)==true) {
    enemyX = nextEX;
    enemyY = nextEY;
  }

  if(enemyXDir == 1) {
    if(enemyFrameTimer.check()) {enemyFrame=(enemyFrame + 1) % 2; enemyFrame=enemyFrame + 1;}
  } else if(enemyXDir == -1) {
    if(enemyFrameTimer.check()) {enemyFrame=(enemyFrame + 1) % 2; enemyFrame=enemyFrame + 1;}
  } else {
    enemyFrame = 0;
  }

  tft.setClipRect(enemyX-enemyMargin, enemyY-enemyMargin, enemyW+enemyMargin, enemyY+enemyMargin);
  drawLevel(curMode);
  tft.drawRGBBitmap(enemyX, enemyY, Game_Pad_Enemy_PIX[enemyFrame], Game_Pad_Enemy_MASK[enemyFrame], enemyW, enemyH);
  tft.updateScreen();
}

void updateEnemy(int x, int y) {
  enemyX = x;
  enemyY = y;
  enemyDraw = true;
}
