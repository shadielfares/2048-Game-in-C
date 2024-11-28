#include "macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the grid with zeros
void initializeGrid(int grid[gridRows][gridCols]) {
    for (int i = 0; i < gridRows; i++) {
        for (int j = 0; j < gridCols; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to add a random tile (2 or 4) to the grid
void addRandomTile(int grid[gridRows][gridCols]) {

    srand(time(NULL));
    int emptyCells = 0;
    int emptyPositions[gridRows * gridCols][2];

    // Find all empty cells
    for (int i = 0; i < gridRows; i++) {
        for (int j = 0; j < gridCols; j++) {
            if (grid[i][j] == 0) {
                emptyPositions[emptyCells][0] = i;
                emptyPositions[emptyCells][1] = j;
                emptyCells++;
            }
        }
    }

    // If there are no empty cells, do nothing
    if (emptyCells == 0) return;

    // Choose a random empty cell
    int randomIndex = rand() % emptyCells;
    int row = emptyPositions[randomIndex][0];
    int col = emptyPositions[randomIndex][1];

    // Add a random tile (90% chance of 2, 10% chance of 4)
    grid[row][col] = (rand() % 10 == 0) ? 4 : 2;
}
