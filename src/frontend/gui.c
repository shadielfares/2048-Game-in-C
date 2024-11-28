#include "raylib.h"
#include "macros.h"

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

void display2048GUI(const int screenHeight, const int screenWidth, const int gameHeight, const int gameWidth, const int tilePadding, const int border, const int tileWidth, const int tileHeight, const int fontAdjustX, const int fontAdjustY, const int fontSize, int grid[gridRows][gridCols]) {

    char string[10];

    BeginDrawing();

    ClearBackground(BACKGROUND);

    int currentX = tilePadding + border;
    int currentY = tilePadding + border + screenHeight - gameHeight;

    for (int row = 0; row < gridRows; row++) {
        for (int col = 0; col < gridCols; col++) {

            char score[] = "Score: 512";

            int centerX = screenWidth * 0.5 + fontAdjustX * strlen(score);
            int centerY = screenHeight * 0.04;
                
            DrawText(score, centerX + 3, centerY + 3, fontSize, DARKBROWN);
            DrawText(score, centerX, centerY, fontSize, WHITE);

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

            if (grid[row][col] != 0) {

                sprintf(string, "%d", grid[row][col]);

                centerX = currentX + (double)tileWidth / 2 + fontAdjustX * strlen(string);
                centerY = currentY + (double)tileHeight / 2 + fontAdjustY;
                
                DrawText(string, centerX + 3, centerY + 3, fontSize, DARKBROWN);
                DrawText(string, centerX, centerY, fontSize, WHITE); 
                
            
            }

            currentX += tileWidth + tilePadding * 2;

        }

        currentX = tilePadding + border;
        currentY += tileHeight + tilePadding * 2;
    }


    EndDrawing();
}