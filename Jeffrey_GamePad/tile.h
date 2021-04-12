#include "Game_Pad_MASK.h"
#include "Game_Pad_PIX.h"

#define tileW 16         // 16 Tiles Across
#define tileH 12         // 12 Tiles Down
#define tileSize 20      // Tile Width (in pixels)
#define numLevels 8     // Number of Levels

int chestL, chestR;
bool chestBool;

void initLevel() {
  chestL = 0x0B;
  chestR = 0x0C;
  chestBool = false;
  
}


//bitmap for the layout of each level
int levels[numLevels][tileW * tileH] {
  // Level 0 - room 1
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x08, 0x08, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x0B, 0x0C, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 1 - room 2
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x0F, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x0F, 0x03,
    0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x09, 0x09, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x09, 0x09, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08,
    0x01, 0x0F, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x0F, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 2 - room 3
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x08, 0x08, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x08, 0x0B, 0x0C, 0x0A, 0x0A, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x03,
    0x01, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08,
    0x01, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08,
    0x01, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 3 - room 4
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x0B, 0x0C, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x0A, 0x0A, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x0F, 0x03,
    0x01, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x01, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
    0x01, 0x09, 0x09, 0x09, 0x09, 0x0A, 0x0A, 0x08, 0x08, 0x0A, 0x0A, 0x09, 0x08, 0x08, 0x0F, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x09, 0x08, 0x08, 0x09, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x0F, 0x08, 0x08, 0x0F, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 4 - room 5
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x08, 0x08, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x08, 0x08, 0x03,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x03,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x0F, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0B, 0x0C, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 5 - room 6
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x08, 0x0B, 0x0C, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x03,
    0x01, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x08, 0x0A, 0x0A, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 6 - room 7
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x08, 0x08, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x0F, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x0F, 0x03,
    0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08,
    0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08,
    0x01, 0x0F, 0x08, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x0F, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x01, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },
  // Level 7 - Boss room
  {
    0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x06,
    0x01, 0x0A, 0x0A, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0A, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x09, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x0A, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x09, 0x0A, 0x0A, 0x0A, 0x03,
    0x01, 0x0A, 0x0A, 0x0A, 0x09, 0x09, 0x0F, 0x08, 0x08, 0x0F, 0x09, 0x09, 0x0A, 0x0A, 0x0A, 0x03,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
    0x10, 0x13, 0x14, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x19, 0x19, 0x19, 0x19, 0x19, 0x13,
    0x11, 0x12, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x15, 0x12,
  },


};

//draws each level based off the bitmap above
void drawLevel(int thisLevel) {
  for (int y = 0; y < tileH; y++) {
    for (int x = 0; x < tileW; x++) {
      int index = x + (y * tileW);
      int whichTile = levels[thisLevel][index];

      int finalX = x * tileSize;
      int finalY = y * tileSize;
      tft.drawRGBBitmap(finalX, finalY, Game_Pad_PIX[whichTile], tileSize, tileSize);
    }
  }
}
