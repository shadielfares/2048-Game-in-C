#include <stdio.h>
#include "../../include/tile_generation.h"

// Utility function to print the grid
void printGrid(int grid[gridRows][gridCols]) {
    for (int i = 0; i < gridRows; i++) {
        for (int j = 0; j < gridCols; j++) {
            printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Test function for addRandomTile
void testAddRandomTile() {
    printf("Testing Random Tile Generation...\n");

    int grid[gridRows][gridCols];
    initializeGrid(grid); // Start with an empty grid

    printf("Grid Before Adding Random Tile:\n");
    printGrid(grid);

    addRandomTile(grid); // Add one random tile

    printf("Grid After Adding Random Tile:\n");
    printGrid(grid);

    // Check if at least one cell in the grid is non-zero
    int isNonEmpty = 0;
    for (int i = 0; i < gridRows; i++) {
        for (int j = 0; j < gridCols; j++) {
            if (grid[i][j] != 0) {
                isNonEmpty = 1;
                break;
            }
        }
        if (isNonEmpty) break;
    }

    if (isNonEmpty) {
        printf("Random Tile Generation Test Passed!\n");
    } else {
        printf("Random Tile Generation Test Failed!\n");
    }
}

int main() {
    testAddRandomTile();
    return 0;
}

