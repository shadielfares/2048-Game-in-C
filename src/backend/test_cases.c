#include <stdio.h>
#include "../../include/merge.h"
#include "../../include/slide.h"
#include "../../include/tile_generation.h"
#include "../../include/scoring.h"
/*
 * GCOV is not 100% due to no failed generation
 */

// Utility function to print a grid
void printGrid(const int grid[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to compare two grids
int compareGrids(const int grid1[4][4], const int grid2[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid1[i][j] != grid2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Test the merge functionality
void testMerge() {
    printf("Testing Merge Function...\n");

    int score = 0;

    // Test Case: Merge Right
    int gridRight[4][4] = {
        {2, 2, 4, 4},
        {4, 4, 0, 0},
        {2, 2, 2, 2},
        {0, 0, 0, 0}
    };
    int expectedRight[4][4] = {
        {0, 4, 0, 8},
        {0, 8, 0, 0},
        {0, 4, 0, 4},
        {0, 0, 0, 0}
    };
    printf("Grid Before Merge Right:\n");
    printGrid(gridRight);
    merge(gridRight, 1, &score); // Direction 1: Right
    printf("Grid After Merge Right:\n");
    printGrid(gridRight);
    if (compareGrids(gridRight, expectedRight)) {
        printf("Merge Right Test Passed!\n");
    } else {
        printf("Merge Right Test Failed!\n");
    }

    // Test Case: Merge Left
    int gridLeft[4][4] = {
        {2, 2, 4, 4},
        {4, 4, 0, 0},
        {2, 2, 2, 2},
        {0, 0, 0, 0}
    };
    int expectedLeft[4][4] = {
        {4, 0, 8, 0},
        {8, 0, 0, 0},
        {4, 0, 4, 0},
        {0, 0, 0, 0}
    };
    printf("Grid Before Merge Left:\n");
    printGrid(gridLeft);
    merge(gridLeft, 2, &score); // Direction 2: Left
    printf("Grid After Merge Left:\n");
    printGrid(gridLeft);
    if (compareGrids(gridLeft, expectedLeft)) {
        printf("Merge Left Test Passed!\n");
    } else {
        printf("Merge Left Test Failed!\n");
    }

    // Test Case: Merge Up
    int gridUp[4][4] = {
        {2, 2, 0, 0},
        {2, 4, 0, 0},
        {4, 4, 4, 4},
        {4, 0, 4, 4}
    };
    int expectedUp[4][4] = {
        {4, 2, 0, 0},
        {0, 8, 0, 0},
        {8, 0, 8, 8},
        {0, 0, 0, 0}
    };
    printf("Grid Before Merge Up:\n");
    printGrid(gridUp);
    merge(gridUp, 3, &score); // Direction 3: Up
    printf("Grid After Merge Up:\n");
    printGrid(gridUp);
    if (compareGrids(gridUp, expectedUp)) {
        printf("Merge Up Test Passed!\n");
    } else {
        printf("Merge Up Test Failed!\n");
    }

    // Test Case: Merge Down
    int gridDown[4][4] = {
        {2, 2, 0, 0},
        {2, 4, 0, 0},
        {4, 4, 4, 4},
        {4, 0, 4, 4}
    };
    int expectedDown[4][4] = {
        {0, 2, 0, 0},
        {4, 0, 0, 0},
        {0, 8, 0, 0},
        {8, 0, 8, 8}
    };
    printf("Grid Before Merge Down:\n");
    printGrid(gridDown);
    merge(gridDown, 4, &score); // Direction 4: Down
    printf("Grid After Merge Down:\n");
    printGrid(gridDown);
    if (compareGrids(gridDown, expectedDown)) {
        printf("Merge Down Test Passed!\n");
    } else {
        printf("Merge Down Test Failed!\n");
    }
}

// Test the slide functionality
void testSlide() {
    printf("Testing Slide Function...\n");

    // Test Case: Slide Right
    int gridRight[4][4] = {
        {0, 2, 2, 4},
        {4, 0, 4, 0},
        {0, 0, 2, 2},
        {0, 0, 0, 0}
    };
    int expectedRight[4][4] = {
        {0, 2, 2, 4},
        {0, 0, 4, 4},
        {0, 0, 2, 2},
        {0, 0, 0, 0}
    };
    printf("Grid Before Slide Right:\n");
    printGrid(gridRight);
    slide(gridRight, 1); // Direction 1: Right
    printf("Grid After Slide Right:\n");
    printGrid(gridRight);
    if (compareGrids(gridRight, expectedRight)) {
        printf("Slide Right Test Passed!\n");
    } else {
        printf("Slide Right Test Failed!\n");
    }

    // Test Case: Slide Left
    int gridLeft[4][4] = {
        {0, 2, 2, 4},
        {4, 0, 4, 0},
        {0, 0, 2, 2},
        {0, 0, 0, 0}
    };
    int expectedLeft[4][4] = {
        {2, 2, 4, 0},
        {4, 4, 0, 0},
        {2, 2, 0, 0},
        {0, 0, 0, 0}
    };
    printf("Grid Before Slide Left:\n");
    printGrid(gridLeft);
    slide(gridLeft, 2); // Direction 2: Left
    printf("Grid After Slide Left:\n");
    printGrid(gridLeft);
    if (compareGrids(gridLeft, expectedLeft)) {
        printf("Slide Left Test Passed!\n");
    } else {
        printf("Slide Left Test Failed!\n");
    }

    // Test Case: Slide Up
    int gridUp[4][4] = {
        {2, 2, 0, 0},
        {2, 0, 4, 4},
        {4, 0, 4, 0},
        {4, 4, 0, 0}
    };
    int expectedUp[4][4] = {
        {2, 2, 4, 4},
        {2, 4, 4, 0},
        {4, 0, 0, 0},
        {4, 0, 0, 0}
    };
    printf("Grid Before Slide Up:\n");
    printGrid(gridUp);
    slide(gridUp, 3); // Direction 3: Up
    printf("Grid After Slide Up:\n");
    printGrid(gridUp);
    if (compareGrids(gridUp, expectedUp)) {
        printf("Slide Up Test Passed!\n");
    } else {
        printf("Slide Up Test Failed!\n");
    }

    // Test Case: Slide Down
    int gridDown[4][4] = {
        {2, 2, 0, 0},
        {2, 0, 4, 4},
        {4, 0, 4, 0},
        {4, 4, 0, 0}
    };
    int expectedDown[4][4] = {
        {2, 0, 0, 0},
        {2, 0, 0, 0},
        {4, 2, 4, 0},
        {4, 4, 4, 4}
    };

    printf("Grid Before Slide Down:\n");
    printGrid(gridDown);
    slide(gridDown, 4); // Direction 4: Down
    printf("Grid After Slide Down:\n");
    printGrid(gridDown);
    if (compareGrids(gridDown, expectedDown)) {
        printf("Slide Down Test Passed!\n");
    } else {
        printf("Slide Down Test Failed!\n");
    }
}

void testTileGeneration(){
    int emptyGrid[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    int fullGrid[4][4] = {
            {2,2,2,2},
            {2,2,2,2},
            {2,2,2,2},
            {2,2,2,2}
    };
    
    int filledGrid[4][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };


    printf("Grid Before Tile Generation:\n");
    printGrid(emptyGrid);

    printf("Grid After Tile Generation:\n");
    addRandomTile(filledGrid); 
    printGrid(filledGrid);

    if (!compareGrids(emptyGrid, filledGrid)) {
        printf("Tile Generation Test Passed!\n");
    } else {
        printf("Tile Generation Test Failed!\n");
    }

    printf("\nTest Case #2 Full Grid:\n");

    printf("Grid Before Tile Generation:\n");
    printGrid(fullGrid);

    printf("Grid After Tile Generation:\n");
    addRandomTile(fullGrid);
    printGrid(fullGrid);
    if (!compareGrids(emptyGrid, filledGrid)) {
        printf("Tile Generation Test Passed!\n");
    } else {
        printf("Tile Generation Test Failed!\n");
    }

    printf("\nTest Case #3 Initalize Grid:\n");

    printf("Grid Before Initalization:\n");
    printGrid(emptyGrid);

    printf("Grid After Initalization:\n");
    initializeGrid(fullGrid);
    printGrid(emptyGrid);
    if (compareGrids(emptyGrid, fullGrid)) {
        printf("Tile Generation Test Passed!\n");
    } else {
        printf("Tile Generation Test Failed!\n");
    }
} 

void testHighScore(){
	initHighScore();
	int score = 100;
	highscore(score);
	score = 200;
	highscore(score);
	score = 100;
	highscore(score);
	
	int highscores[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	puts("Initial list of highscores");
	for(int i = 0; i < 10; i++){
		printf("%d\n", highscores[i]);
	}
	readFile(highscores);
	
	int expectedScores[10] = {200, 100, 100, 0, 0, 0, 0, 0, 0, 0};
	
	puts("New list of highscores");
	for(int i = 0; i < 10; i++){
		printf("%d\n", expectedScores[i]);
		if(highscores[i] != expectedScores[i] && highscores[i] != 0){
			puts("Highscores failed!");
			return;
		}
	}
	
	puts("Highscores passed!");
}

int main() {
    testMerge();
    testSlide();
    testTileGeneration();
    testHighScore();
    return 0;
}
