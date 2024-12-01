#include <stdio.h>
#include "../../include/macros.h"

//int testGrid[gridRows][gridCols] = { {16,8,2,2}, {4,4,0,0}, {0,0,0,0}, {0,0,0,0} };

/*
 * Params: 2D Array
 * Return: Void
 */

//static int score = 0;

void printArray(int matrix[gridRows][gridCols]){

    for(int i = 0; i < gridRows; i++){
        for(int j = 0; j < gridCols ; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
 * Params: int number
 * Return: Sum of number
 */

/*
 * Params: 2D Array
 * Return: Single Row at specified index
 */

int *getRow(int matrix[gridRows][gridCols], int index){
    if (index < 0 || index >= gridRows){
        printf("Fix the index value");
        return NULL;
    } else {
        return matrix[index];
    }
}

/*
 * Params: 2D Array
 * Return: Void (changes Column value)
 */

void getColumn(int matrix[gridRows][gridCols], int index, int column[gridCols]){
    if (index < 0 || index >= gridCols){
        printf("Fix the index value");
    } else {
        for (int i = 0; i < gridCols; i++){
            //Get first index of all rows
            column[i] = matrix[i][index]; 
        }
    }
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Row)
 * Checks RIGHT to LEFT
 */

int *mergeRight(int *row, int *score){
    for (int i = (gridRows-1); i > 0; i--){
        if (row[i] == row[i-1]){
            row[i] += row[i-1];
            *score += 2 * row[i-1];
            row[i-1] = 0;
        }
    }
    return row;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Row LEFT)
 * Checks LEFT to RIGHT 
 */

int *mergeLeft(int *row, int *score){
    for (int i = 0; i < gridRows-1; i++){
        if (row[i+1] == row[i]){
            row[i] += row[i+1];
            *score += 2 * row[i+1];
            row[i+1] = 0;
        }
    }
    return row;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Column)
 * Checks LEFT to RIGHT
 */

int *mergeUp(int *column, int *score){
    for (int i = 0; i < gridCols; i++){
        if (column[i] == column[i+1]){
            column[i] += column[i+1];
            *score += 2 * column[i+1];
            column[i+1] = 0;
        }
    }
    return column;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Column Down)
 * Checks RIGHT to LEFT
 */

int *mergeDown(int *column, int *score){
    for (int i = (gridCols -1); i > 0; i--){
        if (column[i-1] == column[i]){
            column[i] += column[i-1];
            *score += 2 * column[i-1];
            column[i-1] = 0;
        }
    }
    return column;
}

void mergeColumn(int matrix[gridRows][gridCols], int column[gridCols], int index){
        for (int i = 0; i < gridCols; i++){
            //Get first index of all rows
            matrix[i][index] = column[i]; 
        }
}

/*
 * Params: 2D Array, String Direction
 * Return: Depends on Direction
 */

void merge(int matrix[gridRows][gridCols], int direction, int *score){
    //Merging Right = 1
    //Merging Left = 2
    //Merging Up = 3
    //Merging Down = 4
    if (direction == 1){
        for (int i = 0; i < gridRows; i++){
            int *row = getRow(matrix, i);
            mergeRight(row, score);
        }
    }

    if (direction == 2){
        for (int i = 0; i < gridRows; i++){
            int *row = getRow(matrix, i);
            mergeLeft(row, score);
        }
    }

    if (direction == 3){
        int columnArr[gridCols];
        for (int i = 0; i < gridCols; i++){
            getColumn(matrix, i, columnArr);
            mergeColumn(matrix, mergeUp(columnArr, score), i);
        }
    }

    if (direction == 4){
        int columnArr[gridCols];
        for (int i = 0; i < gridCols; i++){
            getColumn(matrix, i, columnArr);
            mergeColumn(matrix, mergeDown(columnArr, score), i);
        }
    }
}

//int main(){
//    printf("PRE MERGE: %d\n", getScore());
//    printf("\nGRID PRE ACTION\n");
//    printArray(testGrid);
//
//    printf("\nPRINTING gridCols MERGED DOWN\n");
//    merge(testGrid, 2);
//    printArray(testGrid);
//
//    printf("POST MERGE: %d\n", getScore());
//    return 0;
//}
