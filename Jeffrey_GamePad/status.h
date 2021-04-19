#include "headsUp_MASK.h"
#include "headsUp_PIX.h"

int heroHealth = 3;

bool swordBool, shieldBool, healthBool1, keyBool;
bool chest1, chest2, chest3, chest4, chest5;

// Show different Heads up Display
void updateHead(int headStatus) {
  tft.setClipRect(2, 200, 48, 48);
  tft.drawRGBBitmap(2, 200, headsUp_PIX[headStatus], 48, 48);
  tft.updateScreen();
}
//draws the sword icon on the hud and "opens the chest"
void updateSword() {
  if (swordBool == true) {
    tft.setClipRect(80, 200, 20, 20);
    tft.drawRGBBitmap(80, 200, Game_Pad_PIX[0x1B], 20, 20);
    tft.updateScreen();
  }
  if (curMode == 0 && chest1 == true) {
    tft.setClipRect(140, 80, 20, 20);
    tft.drawRGBBitmap(140, 80, Game_Pad_PIX[0x0D], 20, 20);
    tft.updateScreen();
    tft.setClipRect(160, 80, 20, 20);
    tft.drawRGBBitmap(160, 80, Game_Pad_PIX[0x0E], 20, 20);
    tft.updateScreen();
    Serial.println("OPENED!");
  }
}
//draws the shield icon on the hud and "opens the chest"
void updateShield() {
  if (shieldBool == true) {
    tft.setClipRect(120, 200, 20, 20);
    tft.drawRGBBitmap(120, 200, Game_Pad_PIX[0x1A], 20, 20);
    tft.updateScreen();
  }
  if (curMode == 4 && chest2 == true) {
    tft.setClipRect(160, 120, 20, 20);
    tft.drawRGBBitmap(160, 120, Game_Pad_PIX[0x0D], 20, 20);
    tft.updateScreen();
    tft.setClipRect(180, 120, 20, 20);
    tft.drawRGBBitmap(180, 120, Game_Pad_PIX[0x0E], 20, 20);
    tft.updateScreen();
    Serial.println("OPENED!");
  }
}
//draws the key icon on the hud and "opens the chest"
void updateKey() {
  if (keyBool == true) {
    tft.setClipRect(160, 200, 20, 20);
    tft.drawRGBBitmap(160, 200, Game_Pad_PIX[0x1D], 20, 20);
    tft.updateScreen();
  }
  if (curMode == 3 && chest5 == true) {
    tft.setClipRect(40, 20, 20, 20);
    tft.drawRGBBitmap(40, 20, Game_Pad_PIX[0x0D], 20, 20);
    tft.updateScreen();
    tft.setClipRect(60, 20, 20, 20);
    tft.drawRGBBitmap(60, 20, Game_Pad_PIX[0x0E], 20, 20);
    tft.updateScreen();
    Serial.println("OPENED!");
  }
}
//increases health by 1 and "opens the chest"
void updateHealth1() {
  if (healthBool1 == true) {
    heroHealth = heroHealth + 1;;
    Serial.println(heroHealth);
    Serial.println("HEALTH!");
    healthBool1 = false;
  }
  if (curMode == 5 && chest3 == true) {
    tft.setClipRect(240, 20, 20, 20);
    tft.drawRGBBitmap(240, 20, Game_Pad_PIX[0x0D], 20, 20);
    tft.updateScreen();
    tft.setClipRect(260, 20, 20, 20);
    tft.drawRGBBitmap(260, 20, Game_Pad_PIX[0x0E], 20, 20);
    tft.updateScreen();
    Serial.println("OPENED!");
  }
  if (curMode == 2 && chest4 == true) {
    tft.setClipRect(220, 20, 20, 20);
    tft.drawRGBBitmap(220, 20, Game_Pad_PIX[0x0D], 20, 20);
    tft.updateScreen();
    tft.setClipRect(240, 20, 20, 20);
    tft.drawRGBBitmap(240, 20, Game_Pad_PIX[0x0E], 20, 20);
    tft.updateScreen();
    Serial.println("OPENED!");
  }
}


//draws the health on hud
void updateHealth() {
  if (heroHealth == 1) {
    tft.setClipRect(280, 200, 20, 20);
    tft.drawRGBBitmap(280, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    Serial.println("HEALTH");
  }
  if (heroHealth == 3) {
    tft.setClipRect(280, 200, 20, 20);
    tft.drawRGBBitmap(280, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(260, 200, 20, 20);
    tft.drawRGBBitmap(260, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    Serial.println("HEALTH");
  }
  if (heroHealth == 3) {
    tft.setClipRect(280, 200, 20, 20);
    tft.drawRGBBitmap(280, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(260, 200, 20, 20);
    tft.drawRGBBitmap(260, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(240, 200, 20, 20);
    tft.drawRGBBitmap(240, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    Serial.println("HEALTH");
  }
  if (heroHealth == 4) {
    tft.setClipRect(280, 200, 20, 20);
    tft.drawRGBBitmap(280, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(260, 200, 20, 20);
    tft.drawRGBBitmap(260, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(240, 200, 20, 20);
    tft.drawRGBBitmap(240, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(220, 200, 20, 20);
    tft.drawRGBBitmap(220, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    Serial.println("HEALTH");
  }
  if (heroHealth == 5) {
    tft.setClipRect(280, 200, 20, 20);
    tft.drawRGBBitmap(280, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(260, 200, 20, 20);
    tft.drawRGBBitmap(260, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(240, 200, 20, 20);
    tft.drawRGBBitmap(240, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(220, 200, 20, 20);
    tft.drawRGBBitmap(220, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    tft.setClipRect(200, 200, 20, 20);
    tft.drawRGBBitmap(200, 200, Game_Pad_PIX[0x17], 20, 20);
    tft.updateScreen();
    Serial.println("HEALTH");
  }
}


void initStatus() {

  updateHead(0);
  chest1 = false;
  chest2 = false;
  chest3 = false;
  chest4 = false;
  swordBool = false;
  shieldBool = false;
  healthBool1 = false;
  heroHealth = 3;
  keyBool = false;
}
