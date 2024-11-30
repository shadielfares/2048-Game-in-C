#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define GRID_SIZE 4

// Global game grid
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

// Function to test the combining tiles method
void testCombineTiles() {
    printf("Testing Combine Tiles...\n");

    // Test case: Combine values in a row
    int testGrid1[GRID_SIZE][GRID_SIZE] = {
        {2, 2, 0, 0},
        {4, 4, 4, 4},
        {8, 0, 8, 8},
        {0, 0, 0, 0}
    };

    int expectedGrid1[GRID_SIZE][GRID_SIZE] = {
        {4, 0, 0, 0},
        {8, 8, 0, 0},
        {16, 8, 0, 0},
        {0, 0, 0, 0}
    };

    // Copy testGrid1 into the global grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = testGrid1[i][j];
        }
    }

    // Apply combining logic
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE - 1; j++) {
            if (grid[i][j] == grid[i][j + 1] && grid[i][j] != 0) {
                grid[i][j] *= 2;
                grid[i][j + 1] = 0;
            }
        }
    }

    // Validate the results
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            assert(grid[i][j] == expectedGrid1[i][j]);
        }
    }
    printf("Combine Tiles Test Passed.\n");
}

// Function to test the sliding tiles method
void testSlideTiles() {
    printf("Testing Slide Tiles...\n");

    // Test case: Slide values to the left
    int testGrid2[GRID_SIZE][GRID_SIZE] = {
        {2, 0, 2, 4},
        {0, 4, 0, 4},
        {8, 0, 8, 0},
        {0, 0, 0, 0}
    };

    int expectedGrid2[GRID_SIZE][GRID_SIZE] = {
        {2, 2, 4, 0},
        {4, 4, 0, 0},
        {8, 8, 0, 0},
        {0, 0, 0, 0}
    };

    // Copy testGrid2 into the global grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = testGrid2[i][j];
        }
    }

    // Apply sliding logic
    for (int i = 0; i < GRID_SIZE; i++) {
        int insertPosition = 0; // Position to insert the next non-zero value
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] != 0) {
                grid[i][insertPosition++] = grid[i][j];
            }
        }
        // Fill remaining cells with zero
        while (insertPosition < GRID_SIZE) {
            grid[i][insertPosition++] = 0;
        }
    }

    // Validate the results
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            assert(grid[i][j] == expectedGrid2[i][j]);
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
