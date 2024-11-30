#include "macros.h"
#include "raylib.h"
void display2048GUI(const int screenHeight, const int screenWidth, const int gameHeight, const int gameWidth, const int tilePadding, const int border, const int tileWidth, const int tileHeight, const int fontAdjustX, const int fontAdjustY, const int fontSize, int grid[gridRows][gridCols]);
void displayText(char* string, int x, int y, Color c);