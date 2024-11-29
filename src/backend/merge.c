#include <stdio.h>
#include "../../include/macros.h"

int testGrid[gridRows][gridCols] = { {2,4,0,0}, {2,4,16,16}, {2,0,0,0}, {2,0,0,0} };

/*
 * Params: 2D Array
 * Return: Void
 */

void printArray(int matrix[gridRows][gridCols]){

    for(int i = 0; i < gridRows; i++){
        for(int j = 0; j < gridCols ; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}


/*
 * Params: Pointer to Array of Ints
 * Return: Void
 */

void printRow(int *row){

    for(int i = 0; i < gridCols; i++){
        printf("%d", row[i]);
    }
    printf("\n");
}

/*
 * Params: Pointer to Array of Ints
 * Return: Void
 */

void printColumn(int *column){

    for(int i = 0; i < gridRows; i++){
        printf("%d", column[i]);
    }
    printf("\n");
}

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

int *mergeRight(int *row){
    for (int i = (gridRows-1); i > 0; i--){
        if (row[i] == row[i-1]){
            row[i] += row[i-1];
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

int *mergeLeft(int *row){
    for (int i = 0; i < gridRows; i++){
        if (row[i+1] == row[i]){
            row[i] += row[i+1];
            row[i+1] = 0;
        }
    }
    return row;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Column)
 * Checks RIGHT to LEFT
 */

int *mergeUp(int *column){
    for (int i = (gridCols-1); i > 0; i--){
        if (column[i-1] == column[i]){
            column[i-1] += column[i];
            column[i] = 0;
        }
    }
    return column;
}

/*
 * Params: Point to Array of Ints (Row)
 * Return: Pointer to Array of Ints (Merged Column Down)
 * Checks Right to Left
 */

int *mergeDown(int *column){
    for (int i = 0; i < gridCols; i++){
        if (column[i+1] == column[i]){
            column[i+1] += column[i];
            column[i] = 0;
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

// 4222

/*
 * Params: 2D Array, String Direction
 * Return: Depends on Direction
 */

void merge(int matrix[gridRows][gridCols], int direction){
    //Merging Right = 1
    //Merging Left = 2
    //Merging Up = 3
    //Merging Down = 4
    if (direction == 1){
        for (int i = 0; i < gridRows; i++){
            int *row = getRow(matrix, i);
            mergeRight(row);
        }
    }

    if (direction == 2){
        for (int i = 0; i < gridRows; i++){
            int *row = getRow(matrix, i);
            mergeLeft(row);
        }
    }

    if (direction == 3){
        int columnArr[gridCols];
        for (int i = 0; i < gridCols; i++){
            getColumn(matrix, i, columnArr);
            mergeUp(columnArr);
            mergeColumn(matrix, mergeUp(columnArr), i);
        }
    }

    if (direction == 4){
        int columnArr[gridCols];
        for (int i = 0; i < gridCols; i++){
            getColumn(matrix, i, columnArr);
            mergeColumn(matrix, mergeDown(columnArr), i);
        }
    }
}

//int main(){
    //printArray(testGrid);
    //int *row1 = getRow(testGrid, 0);
    //int *row2 = getRow(testGrid, 1);

    //printf("\nMERGING LEFT\n");
    //mergeLeft(row1);
    //printRow(row1);

    //printf("\nMERGING RIGHT\n");
    //mergeRight(row2);
    //printRow(row2);

    //printf("\nGRID PRE ACTION\n");
    //printArray(testGrid);

    //printf("\nPRINTING gridCols MERGED DOWN\n");
    //merge(testGrid, 2);
    //printArray(testGrid);
    //return 0;
//}
