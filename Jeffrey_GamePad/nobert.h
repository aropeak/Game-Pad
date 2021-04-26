#include "Norbert_MASK.h"
#include "Norbert_PIX.h"

int norbX, norbY, norbW, norbH, norbHealth, norbertFrame;

Metro norbertFrameTimer = Metro(250);

void initNorbert() {
  norbX = 120;
  norbY = 25;
  norbW = 80;
  norbH = 64;
  norbHealth = 3;
  norbertFrame = 0;
}

void drawNorbert() {


  tft.setClipRect(norbX , norbY , norbW, norbH);
  tft.drawRGBBitmap(norbX, norbY, Norbert_PIX[norbertFrame], Norbert_MASK[norbertFrame], norbW, norbH);
  tft.updateScreen();
}
