#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include "../../include/macros.h"

#define BACKGROUND (Color){188, 172, 159, 255}
#define EMPTY_TILE (Color){204, 193, 180, 255}
#define TILE2      (Color){245, 233, 206, 255}
#define TILE4      (Color){247, 224, 171, 255}
#define TILE8      (Color){245, 191, 105, 255}
#define TILE16     (Color){237, 159, 90, 255}
#define TILE32     (Color){237, 122, 59, 255}
#define TILE64     (Color){237, 86, 59, 255}
#define TILE128    (Color){247, 214, 106, 255}
#define TILE256    (Color){247, 203, 57, 255}
#define TILE512    (Color){252, 196, 13, 255}
#define TILE1024   (Color){217, 167, 2, 255}
#define TILE2048   (Color){54, 201, 24, 255}
#define TEXTBLANK  (Color){0, 0, 0, 0}
#define WHITEc (Color){255, 255, 255, 255}
#define DARKBROWNc (Color){ 76, 63, 47, 255 } 

void displayText(char * string, int x, int y, Color c) {

    int textHeight = 35;
    int textWidth = 25;
    int lineThickness = 5;
    int currentX = x;
    int currentY = y;
    int charSpacing = 5;

                  // 0, 1, 2, 3, 4, 5, 6
    Color num[10][7] =     {{c, c, c, c, c, c, TEXTBLANK},
                        { TEXTBLANK, c, c, TEXTBLANK, TEXTBLANK, TEXTBLANK, TEXTBLANK},
                        { c, c, TEXTBLANK, c, c, TEXTBLANK, c},
                        { c, c, c, c, TEXTBLANK, TEXTBLANK, c},
                        { TEXTBLANK, c, c, TEXTBLANK, TEXTBLANK, c, c },
                        { c, TEXTBLANK, c, c, TEXTBLANK, c, c},
                        { c, TEXTBLANK, c, c, c, c, c},
                        { c, c, c, TEXTBLANK, TEXTBLANK, TEXTBLANK, TEXTBLANK},
                        { c, c, c, c, c, c, c},
                        { c, c, c, TEXTBLANK, TEXTBLANK, c, c}};

    for (int i = 0; i < strlen(string); i++) {

        int val = string[i] - '0';

        if (val != 1) {

            DrawRectangle(currentX, currentY, textWidth, lineThickness, num[val][0]); //seg 0
            DrawRectangle(currentX + textWidth - lineThickness, currentY, lineThickness, textHeight / 2, num[val][1]); //seg 1
            DrawRectangle(currentX + textWidth - lineThickness, currentY + textHeight / 2, lineThickness, textHeight / 2, num[val][2]); //seg 2
            DrawRectangle(currentX, currentY + textHeight - lineThickness, textWidth, lineThickness, num[val][3]); //seg 3
            DrawRectangle(currentX, currentY + textHeight / 2, lineThickness, textHeight / 2, num[val][4]); //seg 4
            DrawRectangle(currentX, currentY, lineThickness, textHeight / 2, num[val][5]); //seg 5
            DrawRectangle(currentX, currentY + 3 * lineThickness, textWidth, lineThickness, num[val][6]); //seg 6

            currentX += 5 + textWidth;

        }

        else {

            DrawRectangle(currentX + lineThickness, currentY, lineThickness, textHeight, c); //1

            currentX += 5 + lineThickness * 2;

        }
        
        
        

    }

}

void display2048GUI(const int screenHeight, const int screenWidth, const int gameHeight, const int gameWidth, const int tilePadding, const int border, const int tileWidth, const int tileHeight, const int fontAdjustX, const int fontAdjustY, const int fontSize, int grid[gridRows][gridCols]) {

    char string[10];

    BeginDrawing();

    ClearBackground(BACKGROUND);

    int currentX = tilePadding + border;
    int currentY = tilePadding + border + screenHeight - gameHeight;

    for (int row = 0; row < gridRows; row++) {
        for (int col = 0; col < gridCols; col++) {

            char score[] = "Score: 512";

            int centerX = screenWidth - 400 + fontAdjustX * strlen(score);
            int centerY = 36;
                
            DrawText(score, centerX + 3, centerY + 3, fontSize, DARKBROWNc);
            DrawText(score, centerX, centerY, fontSize, WHITEc);

            DrawRectangle(currentX, currentY, tileWidth, tileHeight, EMPTY_TILE);

            switch (grid[row][col]) {

            case 2:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE2);
                break;
            case 4:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE4);
                break;
            case 8:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE8);
                break;
            case 16:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE16);
                break;
            case 32:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE32);
                break;
            case 64:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE64);
                break;
            case 128:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE128);
                break;
            case 256:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE256);
                break;
            case 512:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE512);
                break;
            case 1024:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE1024);
                break;
            case 2048:
                DrawRectangle(currentX, currentY, tileWidth, tileHeight, TILE2048);
                break;
            default:
                break;
            }

            //DrawRectangle(50, 50, 100, 100, DARKBROWNc);

            if (grid[row][col] != 0) {

                sprintf(string, "%d", grid[row][col]);

                centerX = (int) (currentX + tileWidth / 2 + fontAdjustX * strlen(string));
                centerY = (int) (currentY + tileHeight / 2 + fontAdjustY);
                
                displayText(string, centerX + 3, centerY + 3, DARKBROWNc);
                displayText(string, centerX, centerY, WHITEc); 
                
            
            }

            currentX += tileWidth + tilePadding * 2;

        }

        currentX = tilePadding + border;
        currentY += tileHeight + tilePadding * 2;
    }


    EndDrawing();
}