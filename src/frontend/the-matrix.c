// Initializes GUI and contains primary gameloop for The Matrix game
// Created by Kurlan, Shadi, Aiden, and Akshayan; McMaster University, 2024/12/05

#include "raylib.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../../include/scoring.h"
#include "../../include/gui.h"
#include "../../include/macros.h"
#include "../../include/tile_generation.h"
#include "../../include/merge.h"
#include "../../include/slide.h"


//----------------------- -------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

// Handles the primary gameloop and accesses player high-score
// Globals: N/A
// Arguments: number of arguments, arguments
// Outputs: The GUI of the game (within gamePlay function), and a final highscore
// Returns: int

int main(int argc, char *argv[])
{   

	// Display --help flags to the user
	// Provides instructions on how to play the game
    if (argc >= 2 && strcmp(argv[1], "--help") == 0) {

        printf("----Welcome to The Matrix----\n");
        printf("1. Use arrow keys to shift tiles\n");
        printf("2. Merge blocks to get the largest number possible\n");
        printf("3. Try to get to a score of 2048!\n");

    }

    else {

		// Initialize screen size
	    const int screenWidth = 800;
	    const int screenHeight = 900;
	    InitWindow(screenWidth, screenHeight, "The Matrix");

		// Access locally saved highscores
	    FILE *file;
	    char *fileName = "highscore.txt";

	    if((file = fopen(fileName, "r")) == NULL){
		initHighScore();
	    } else {
	    	fclose(file);
	    }

		// Begin main game-loop
	    gamePlay(screenWidth, screenHeight);
}
