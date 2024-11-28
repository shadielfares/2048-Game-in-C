#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

// Global game grid
int grid[GRID_SIZE][GRID_SIZE];

// Function to initialize the grid with zeros
void initializeGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to add a random tile (2 or 4) to the grid
void addRandomTile() {
    int emptyCells = 0;
    int emptyPositions[GRID_SIZE * GRID_SIZE][2];

    // Find all empty cells
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
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

// Function to print the grid
void printGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize the game grid
    initializeGrid();

    // Add two random tiles at the start
    addRandomTile();
    addRandomTile();

    // Print the initial grid
    printGrid();

    return 0;
}
