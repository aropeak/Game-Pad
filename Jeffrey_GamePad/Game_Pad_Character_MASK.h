const uint8_t Game_Pad_Character_MASK[10][72] PROGMEM={
{0, 0, 0, 1, 255, 252, 1, 255, 252, 1, 255, 248, 1, 255, 224, 3, 255, 224, 3, 255, 224, 3, 255, 224, 3, 255, 224, 1, 255, 224, 15, 255, 192, 31, 255, 240, 31, 255, 248, 63, 255, 252, 63, 255, 252, 63, 255, 252, 63, 255, 252, 31, 255, 248, 31, 255, 248, 15, 255, 240, 15, 231, 240, 31, 195, 248, 63, 195, 252, 63, 129, 252, },
{0, 0, 0, 1, 255, 252, 1, 255, 252, 1, 255, 248, 1, 255, 224, 3, 255, 224, 3, 255, 224, 3, 255, 224, 15, 255, 224, 63, 255, 238, 127, 255, 223, 127, 255, 223, 255, 255, 255, 255, 255, 255, 251, 255, 255, 251, 255, 254, 113, 255, 252, 13, 252, 120, 31, 255, 48, 63, 255, 128, 127, 255, 192, 127, 207, 224, 60, 15, 240, 24, 7, 240, },
{0, 0, 0, 1, 255, 252, 1, 255, 252, 1, 255, 248, 1, 255, 224, 3, 255, 224, 3, 255, 224, 3, 255, 224, 7, 255, 224, 15, 255, 224, 31, 255, 192, 63, 255, 192, 63, 255, 128, 31, 255, 128, 31, 255, 192, 15, 255, 192, 7, 251, 128, 3, 252, 0, 1, 252, 0, 3, 248, 0, 7, 240, 0, 15, 224, 0, 15, 240, 0, 7, 240, 0, },
{0, 0, 0, 1, 255, 252, 1, 255, 252, 1, 255, 248, 1, 255, 224, 3, 255, 224, 3, 255, 224, 3, 255, 224, 15, 255, 224, 63, 255, 224, 127, 255, 192, 127, 255, 128, 255, 255, 252, 255, 255, 254, 251, 255, 254, 251, 255, 254, 113, 255, 252, 13, 252, 0, 31, 255, 0, 63, 255, 128, 127, 255, 192, 127, 207, 224, 60, 15, 240, 24, 7, 240, },
{0, 0, 0, 63, 255, 128, 63, 255, 128, 31, 255, 128, 7, 255, 128, 7, 255, 192, 7, 255, 192, 7, 255, 192, 7, 255, 192, 7, 255, 128, 3, 255, 240, 15, 255, 248, 31, 255, 248, 63, 255, 252, 63, 255, 252, 63, 255, 252, 63, 255, 252, 31, 255, 248, 31, 255, 248, 15, 255, 240, 15, 231, 240, 31, 195, 248, 63, 195, 252, 63, 129, 252, },
{0, 0, 0, 63, 255, 128, 63, 255, 128, 31, 255, 128, 7, 255, 128, 7, 255, 192, 7, 255, 192, 7, 255, 192, 7, 255, 240, 119, 255, 252, 251, 255, 254, 251, 255, 254, 255, 255, 255, 255, 255, 255, 255, 255, 223, 127, 255, 223, 63, 255, 142, 30, 63, 176, 12, 255, 248, 1, 255, 252, 3, 255, 254, 7, 243, 254, 15, 240, 60, 15, 224, 24, },
{0, 0, 0, 63, 255, 128, 63, 255, 128, 31, 255, 128, 7, 255, 128, 7, 255, 192, 7, 255, 192, 7, 255, 192, 7, 255, 224, 7, 255, 240, 3, 255, 248, 3, 255, 252, 1, 255, 252, 1, 255, 248, 3, 255, 248, 3, 255, 240, 1, 223, 224, 0, 63, 192, 0, 63, 128, 0, 31, 192, 0, 15, 224, 0, 7, 240, 0, 15, 240, 0, 15, 224, },
{0, 0, 0, 63, 255, 128, 63, 255, 128, 31, 255, 128, 7, 255, 128, 7, 255, 192, 7, 255, 192, 7, 255, 192, 7, 255, 240, 7, 255, 252, 3, 255, 254, 1, 255, 254, 63, 255, 255, 127, 255, 255, 127, 255, 223, 127, 255, 223, 63, 255, 142, 0, 63, 176, 0, 255, 248, 1, 255, 252, 3, 255, 254, 7, 243, 254, 15, 240, 60, 15, 224, 24, },
{0, 0, 0, 1, 255, 252, 1, 255, 252, 1, 255, 248, 1, 255, 224, 3, 255, 224, 3, 255, 238, 3, 255, 255, 3, 255, 255, 1, 255, 255, 15, 255, 223, 31, 255, 255, 31, 255, 255, 63, 255, 255, 63, 255, 255, 63, 255, 255, 63, 255, 255, 31, 255, 255, 31, 255, 255, 15, 255, 255, 15, 231, 255, 31, 195, 254, 63, 195, 252, 63, 129, 252, },
{0, 0, 0, 63, 255, 128, 63, 255, 128, 31, 255, 128, 7, 255, 128, 7, 255, 192, 119, 255, 192, 255, 255, 192, 255, 255, 192, 255, 255, 128, 251, 255, 240, 255, 255, 248, 255, 255, 248, 255, 255, 252, 255, 255, 252, 255, 255, 252, 255, 255, 252, 255, 255, 248, 255, 255, 248, 255, 255, 240, 255, 231, 240, 127, 195, 248, 63, 195, 252, 63, 129, 252, },
};
