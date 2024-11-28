/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

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
   
#define gridRows 4
#define gridCols 4
//----------------------- -------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int fontSize = 50;
    const int fontAdjustX = -13;
    const int fontAdjustY = -20;
        
    // Defined as the padding on one side of the tile/border on one side of the screen
    const int border = 10;
    const int tilePadding = 10;

    const int tileWidth =  (int) ((double) (screenWidth - border * 2) / (double) gridCols - (double) (2 * tilePadding));
    const int tileHeight = (int) ((double) (screenHeight - border * 2) / (double) gridRows - (double) (2 * tilePadding));


    int grid[gridRows][gridCols] = {{0, 256, 1024, 4}, 
                                    {0, 0, 0, 4}, 
                                    {64, 2, 0, 8}, 
                                    {32, 2, 16, 4}};

    InitWindow(screenWidth, screenHeight, "2048");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    char string[10];

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BACKGROUND);

            int currentX = tilePadding + border;
            int currentY = tilePadding + border;

            for (int row = 0; row < gridRows; row++) {
                for (int col = 0; col < gridCols; col++) {

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

                        const int centerX = currentX + (double)tileWidth / 2 + fontAdjustX * strlen(string);
                        const int centerY = currentY + (double)tileHeight / 2 + fontAdjustY;

                        DrawText(string, centerX, centerY, fontSize, WHITE);

                    }

                    currentX += tileWidth + tilePadding * 2;

                }

                currentX = tilePadding + border;
                currentY += tileHeight + tilePadding * 2;
            }
            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}