#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/gui.h"
#include "../../include/macros.h"
#include "../../include/tile_generation.h"
#include "../../include/merge.h"
#include "../../include/slide.h"


//----------------------- -------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{   

    if (argc >= 2 && strcmp(argv[1], "--help") == 0) {

        printf("----Welcome to The Matrix----\n");
        printf("1. Use arrow keys to shift tiles\n");
        printf("2. Merge blocks to get the largest number possible\n");
        printf("3. Try to get to a score of 2048!\n");

    }

    else {

        // Initialization
    //-------------------------------------------------------------------------------------

        const int screenWidth = 800;
        const int screenHeight = 900;

        const int gameWidth = screenWidth;
        const int gameHeight = 800;

        const int fontSize = 50;
        const int fontAdjustX = -13;
        const int fontAdjustY = -20;

        // Defined as the padding on one side of the tile/border on one side of the screen
        const int border = 10;
        const int tilePadding = 10;

        const int tileWidth = (int)((double)(gameWidth - border * 2) / (double)gridCols - (double)(2 * tilePadding));
        const int tileHeight = (int)((double)(gameHeight - border * 2) / (double)gridRows - (double)(2 * tilePadding));


        int grid[gridRows][gridCols];

        initializeGrid(grid);
	addRandomTile(grid);
	addRandomTile(grid);

        InitWindow(screenWidth, screenHeight, "The Matrix");

        SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            //int oldGrid[gridRows][gridCols] = grid;
            
		display2048GUI(screenHeight, screenWidth, gameHeight, gameWidth, tilePadding, border, tileWidth, tileHeight, fontAdjustX, fontAdjustY, fontSize, grid);

	   
	    	if (IsKeyPressed(KEY_RIGHT)) {
                	printf("Right");
			slideRight(grid, 0);
            merge(grid,1);
			slideRight(grid, 0);
	    	}
            	else if (IsKeyPressed(KEY_DOWN)) {
                	printf("Down");
			slideDown(grid, 0);
            merge(grid,4);
			slideRight(grid, 0);
	    	}
            	else if (IsKeyPressed(KEY_LEFT)) {
                	printf("Left");
			slideLeft(grid, 0);
            merge(grid,2);
			slideRight(grid, 0);
	    	}
            	else if (IsKeyPressed(KEY_UP)) {
                	printf("Up");
			slideUp(grid, 0);
            merge(grid,3);
			slideRight(grid, 0);
	    	} else {
	    		continue;
	    	}
	   	
		addRandomTile(grid);

            display2048GUI(screenHeight, screenWidth, gameHeight, gameWidth, tilePadding, border, tileWidth, tileHeight, fontAdjustX, fontAdjustY, fontSize, grid);


        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

        return 0;
    }
}
