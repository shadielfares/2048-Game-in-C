#include <stdio.h>
#include "merge.h"
#include "slide.h"

void printGrid(const int grid[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void testMerge() {
    printf("Testing Merge Function...\n");
    int grid[4][4] = {
        {2, 2, 4, 4},
        {4, 0, 4, 0},
        {2, 2, 2, 2},
        {0, 0, 0, 0}
    };
    int expectedGrid[4][4] = {
        {4, 8, 0, 0},
        {8, 0, 0, 0},
        {4, 4, 0, 0},
        {0, 0, 0, 0}
    };
    int score = 0;

    merge(grid, 1, &score); // Merge Right
    printf("After Merge Right:\n");
    printGrid(grid);

    // Check for correctness
    int isCorrect = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != expectedGrid[i][j]) {
                printf("Mismatch at [%d][%d]: Expected %d, Got %d\n",
                       i, j, expectedGrid[i][j], grid[i][j]);
                isCorrect = 0;
            }
        }
    }
    if (isCorrect) {
        printf("Merge Test Passed!\n");
    } else {
        printf("Merge Test Failed!\n");
    }
}

void testSlide() {
    printf("Testing Slide Function...\n");
    int grid[4][4] = {
        {0, 2, 2, 4},
        {4, 0, 4, 0},
        {0, 0, 2, 2},
        {0, 0, 0, 0}
    };
    int expectedGrid[4][4] = {
        {4, 4, 0, 0},
        {8, 0, 0, 0},
        {4, 0, 0, 0},
        {0, 0, 0, 0}
    };

    slide(grid, 1); // Slide Right
    printf("After Slide Right:\n");
    printGrid(grid);

    // Check for correctness
    int isCorrect = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != expectedGrid[i][j]) {
                printf("Mismatch at [%d][%d]: Expected %d, Got %d\n",
                       i, j, expectedGrid[i][j], grid[i][j]);
                isCorrect = 0;
            }
        }
    }
    if (isCorrect) {
        printf("Slide Test Passed!\n");
    } else {
        printf("Slide Test Failed!\n");
    }
}

int main() {
    testMerge();
    testSlide();
    return 0;
}
