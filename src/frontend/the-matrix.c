#include "raylib.h"
#include "gui.h"
#include "macros.h"

//----------------------- -------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------

    const int screenWidth = 800;
    const int screenHeight = 800;

    const int fontSize = 50;
    const int fontAdjustX = -13;
    const int fontAdjustY = -20;

    // Defined as the padding on one side of the tile/border on one side of the screen
    const int border = 10;
    const int tilePadding = 10;

    const int tileWidth = (int)((double)(screenWidth - border * 2) / (double)gridCols - (double)(2 * tilePadding));
    const int tileHeight = (int)((double)(screenHeight - border * 2) / (double)gridRows - (double)(2 * tilePadding));


    int grid[gridRows][gridCols] = {{0, 256, 1024, 4}, 
                                    {0, 0, 0, 4}, 
                                    {64, 2, 0, 8}, 
                                    {32, 2, 16, 4}};

    InitWindow(screenWidth, screenHeight, "2048");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        if (IsKeyPressed(KEY_RIGHT)) {
            printf("Right");
        }
        else if (IsKeyPressed(KEY_DOWN)) {
            printf("Down");
        }
        else if (IsKeyPressed(KEY_LEFT)) {
            printf("Left");
        }
        else if (IsKeyPressed(KEY_UP)) {
            printf("Up");
        }

        display2048GUI(tilePadding, border, tileWidth, tileHeight, fontAdjustX, fontAdjustY, fontSize, grid);
       
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}