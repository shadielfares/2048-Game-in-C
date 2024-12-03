#include <stdio.h>
#include <assert.h>

#define GRID_SIZE 4

int grid[GRID_SIZE][GRID_SIZE];

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

// Function to copy a test grid into the global grid
void copyGrid(int source[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = source[i][j];
        }
    }
}

// Updated combineLeft function
void combineLeft() {
    for (int i = 0; i < GRID_SIZE; i++) {
        int insertPosition = 0; // Position to insert the next valid tile
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != 0) {
                if (insertPosition > 0 && grid[i][insertPosition - 1] == grid[i][j]) {
                    // Combine with the previous tile
                    grid[i][insertPosition - 1] *= 2;
                    grid[i][j] = 0;
                } else {
                    // Move the tile to the insert position
                    if (insertPosition != j) {
                        grid[i][insertPosition] = grid[i][j];
                        grid[i][j] = 0;
                    }
                    insertPosition++;
                }
            }
        }
    }
}

// Function to slide tiles to the left
void slideLeft() {
    for (int i = 0; i < GRID_SIZE; i++) {
        int insertPosition = 0;
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != 0) {
                grid[i][insertPosition++] = grid[i][j];
            }
        }
        while (insertPosition < GRID_SIZE) {
            grid[i][insertPosition++] = 0;
        }
    }
}

// Function to test the combining tiles method
void testCombineTiles() {
    printf("Testing Combine Tiles...\n");

    int testGrid[4][4] = {
        {2, 2, 0, 0},
        {4, 4, 4, 4},
        {8, 0, 8, 8},
        {0, 0, 0, 0}
    };
    int expectedGrid[4][4] = {
        {4, 0, 0, 0},
        {8, 8, 0, 0},
        {16, 8, 0, 0},
        {0, 0, 0, 0}
    };

    copyGrid(testGrid);

    printf("Grid Before Combine:\n");
    printGrid();

    combineLeft();

    printf("Grid After Combine:\n");
    printGrid();

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != expectedGrid[i][j]) {
                printf("Mismatch at [%d][%d]: Expected %d, Got %d\n",
                       i, j, expectedGrid[i][j], grid[i][j]);
            }
            assert(grid[i][j] == expectedGrid[i][j]);
        }
    }
    printf("Combine Tiles Test Passed.\n");
}

// Function to test the sliding tiles method
void testSlideTiles() {
    printf("Testing Slide Tiles...\n");

    int testGrid[4][4] = {
        {2, 0, 2, 4},
        {0, 4, 0, 4},
        {8, 0, 8, 0},
        {0, 0, 0, 0}
    };
    int expectedGrid[4][4] = {
        {2, 2, 4, 0},
        {4, 4, 0, 0},
        {8, 8, 0, 0},
        {0, 0, 0, 0}
    };

    copyGrid(testGrid);

    printf("Grid Before Slide:\n");
    printGrid();

    slideLeft();

    printf("Grid After Slide:\n");
    printGrid();

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != expectedGrid[i][j]) {
                printf("Mismatch at [%d][%d]: Expected %d, Got %d\n",
                       i, j, expectedGrid[i][j], grid[i][j]);
            }
            assert(grid[i][j] == expectedGrid[i][j]);
        }
    }
    printf("Slide Tiles Test Passed.\n");
}

int main() {
    // Run test cases
    testCombineTiles();
    testSlideTiles();

    return 0;
}
