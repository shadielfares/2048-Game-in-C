// Handles accepting user input and displaying the game
// Created by Aiden, Kerlan; McMaster University, 2024/12/05

#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../../include/macros.h"
#include "../../include/merge.h"
#include "../../include/gui.h"
#include "../../include/macros.h"
#include "../../include/tile_generation.h"
#include "../../include/slide.h"
#include "../../include/scoring.h"

// Defining colour macros for various tile types

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

// Custom 7-segment display that renders digits (0-9) onto the screen
// Arguments: text in string format, an x and y coordinate (integers), and the text colour
// Outputs: digits (0-9) to the screen to display the value of each tile
// Returns: N/A

// This function was created as a result of the drawText function not
// working in Ubuntu environments; the issue was later rectified but
// this custom displayText code was kept since it produces results virtually 
// indentical to drawText, and was a fun programming challenge :)
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

// Displays the 2048-style grid to the screen
// Arguments: screen height (int), screen width (int), game window height (int), game window width (int), 
//            padding around tiles (int), padding for the border (int), tile width (int), tile height (int),
//            font horizontal offset (int), font vertical offset (int), font size (int), 2D array of ints to represent the grid, and the current score (int)
// Outputs: The 2048-style grid, containing the values of each coloured tile
// Returns: N/A

void display2048GUI(const int screenHeight, const int screenWidth, const int gameHeight, const int gameWidth, const int tilePadding, const int border, const int tileWidth, const int tileHeight, const int fontAdjustX, const int fontAdjustY, const int fontSize, int grid[gridRows][gridCols], int scoreNum) {
	
    char string[10];
    char score[100];
    
    BeginDrawing();
    
    ClearBackground(BACKGROUND);
    
    int currentX = tilePadding + border;
    int currentY = tilePadding + border + screenHeight - gameHeight;
    
    for (int row = 0; row < gridRows; row++) {
        for (int col = 0; col < gridCols; col++) {

            sprintf(score, "Score: %d", scoreNum);

            int centerX = screenWidth - 400 + fontAdjustX * strlen(score);
            int centerY = 36;
                
            DrawText(score, centerX + 3, centerY + 3, fontSize, DARKBROWNc);
            DrawText(score, centerX, centerY, fontSize, WHITEc);

            DrawRectangle(currentX, currentY, tileWidth, tileHeight, EMPTY_TILE);

            // Decides what colour to draw the tile based on its numerical value
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

            // Displays the value of each tile in its center

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

// Primary gameloop; takes player input and interfaces with all other functions
// Arguments: screen width (int), screen height (int)
// Outputs: The entire game, including the GUI interface, start and end menu
// Returns: N/A
void gamePlay(const int screenWidth, const int screenHeight){
        //const int screenWidth = 800;
        //const int screenHeight = 900;

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
	int done = 0;
	int initialScore = 0;
	int *scoreNum = &initialScore;

        initializeGrid(grid);
	addRandomTile(grid);
	addRandomTile(grid);

        //InitWindow(screenWidth, screenHeight, "The Matrix");

        SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose() && done == 0)    // Detect window close button or ESC key
        {
            	int oldGrid[gridRows][gridCols];
            
		for(int r = 0; r < gridRows; r++){
			for(int c = 0; c < gridCols; c++){
				oldGrid[r][c] = grid[r][c];
			}
		}
			
		display2048GUI(screenHeight, screenWidth, gameHeight, gameWidth, tilePadding, border, tileWidth, tileHeight, fontAdjustX, fontAdjustY, fontSize, grid, *scoreNum);

            // Detects user input and performs tile sliding and merging
	    	if (IsKeyPressed(KEY_RIGHT)) {
			slide(grid, 1);
            		merge(grid,1, scoreNum);
			slide(grid, 1);
	    	}
            	else if (IsKeyPressed(KEY_DOWN)) {	
			slide(grid, 4);
            		merge(grid,4, scoreNum);
			slide(grid, 4);
	    	}
            	else if (IsKeyPressed(KEY_LEFT)) {
			slide(grid, 2);
            		merge(grid,2, scoreNum);
			slide(grid, 2);
	    	}
            	else if (IsKeyPressed(KEY_UP)) {
			slide(grid, 3);
            		merge(grid,3, scoreNum);
			slide(grid, 3);
	    	} else {
	    		continue;
	    	}

        // Checks if there are no more moves available to the player
		bool movement = false;
		bool fullTiles = true;
		int isMerge = 0;

		for(int r = 0; r < gridRows; r++){
			for(int c = 0; c < gridCols; c++){
				if(oldGrid[r][c] != grid[r][c]){
					movement = true;
				}
				
				if(grid[r][c] == 2048){	
				        done = 2;
			        }	       
			}
		}
		
        // Generates random tile between moves
		if(movement){
			addRandomTile(grid);
		}

        // Continues merging tiles until no more valid merges remain

		for(int r = 0; r < gridRows; r++){
                        for(int c = 0; c < gridCols; c++){
				if(grid[r][c] == 0){
                                        fullTiles = false;
                                }
				if(grid[r][c] != 0){
					if(grid[r][c] == grid[r+1][c] && r != gridRows - 1){
						isMerge++;
					} else if(grid[r][c] == grid[r][c+1] && c != gridCols - 1){
						isMerge++;
					}
				} else {
					isMerge++;
				}
			}
		}

            display2048GUI(screenHeight, screenWidth, gameHeight, gameWidth, tilePadding, border, tileWidth, tileHeight, fontAdjustX, fontAdjustY, fontSize, grid, *scoreNum);
	
		if(!fullTiles || isMerge > 0){
			continue;
		} else {
			done = 1;
		}
	}

	highscore(*scoreNum);
	win(*scoreNum, done);
}


// Handles the win and loss condition
// Arguments: score (int), current status of the game (int)
// Outputs: Displays whether the user won or lost,
//          and updates the user's highscore in the text file
// Returns: N/A
void win(int score, int win){
	const int screenWidth = 800;
	const int screenHeight = 900;


	int new_highscore[10] = {0};
	readFile(new_highscore);
	char text5[1000] = "";
	

	for(int i = 1; i <= 10; i++){
		char temp[1000];
		sprintf(temp, "%*d. %05d\n", 2, i, new_highscore[i - 1]);
	 	strcat(text5, temp);
	}

	while(!WindowShouldClose() && !IsKeyPressed(KEY_R) && !IsKeyPressed(KEY_Q)){
		
		const char* text0 = "You Lost :(";
		const char* text1 = "You Win! :)";
		const int fontSize1 = 80;
		const char* text2 = "Press 'R' To Play Again";
		const char* text3 = TextFormat("Final Score: %d", score);
		const int fontSize3 = 40;
		const int fontSize2 = 45;
		const char* text4 = "Press 'Q' To Quit The Game";
		const int fontSize4 = 30;
		const char* text6 = "HIGHSCORES";

		const int x1 = (800 - MeasureText(text0, fontSize1)) * 0.5f;
		const int x2 = (800 - MeasureText(text2, fontSize2)) * 0.5f;
		const int x3 = (800 - MeasureText(text3, fontSize3)) * 0.5f;
		const int x4 = (800 - MeasureText(text4, fontSize4)) * 0.5f;
		const int x5 = (800 - MeasureText((const char *)text5, fontSize3)) * 0.5f;
		const int x6 = (800 - MeasureText(text6, fontSize2)) * 0.5f;	

        // Displays the appropriate win/loss screen depending on the game state
		BeginDrawing();
		{
			ClearBackground(TILE2);

			if(win == 2){
				DrawText(text1, x1, 50, fontSize1, DARKBROWNc);
			} else {
				DrawText(text0, x1, 50, fontSize1, DARKBROWNc);
			}

			DrawText(text3, x3, 150, fontSize3, BACKGROUND);
			DrawText(text2, x2, 780, fontSize2, DARKBROWNc);
			DrawText(text4, x4, 850, fontSize4, BACKGROUND);
			DrawText((const char *)text5, x5, 300, fontSize3, DARKBROWNc);
			DrawText(text6, x6, 225, fontSize2, DARKBROWNc);
		}
		EndDrawing();
	}

    // Allows user to restart or quit the game

	if (IsKeyPressed(KEY_R))
        {
        	gamePlay(screenWidth, screenHeight);
        } else if(IsKeyPressed(KEY_Q)) {
		CloseWindow();
	} 
}
