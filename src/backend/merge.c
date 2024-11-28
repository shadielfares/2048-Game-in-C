#include <stdio.h>

#define ROWS 4
#define COLUMNS 4

int testGrid[ROWS][COLUMNS] = { {2,4,0,0}, {2,4,16,16}, {2,0,0,0}, {2,0,0,0} };

/*
 * Params: 2D Array
 * Return: Void
 */

void printArray(int matrix[ROWS][COLUMNS]){

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS ; j++){
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

    for(int i = 0; i < COLUMNS; i++){
        printf("%d", row[i]);
    }
    printf("\n");
}

/*
 * Params: Pointer to Array of Ints
 * Return: Void
 */

void printColumn(int *column){

    for(int i = 0; i < ROWS; i++){
        printf("%d", column[i]);
    }
    printf("\n");
}

/*
 * Params: 2D Array
 * Return: Single Row at specified index
 */

int *getRow(int matrix[ROWS][COLUMNS], int index){
    if (index < 0 || index >= ROWS){
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

void getColumn(int matrix[ROWS][COLUMNS], int index, int column[COLUMNS]){
    if (index < 0 || index >= COLUMNS){
        printf("Fix the index value");
    } else {
        for (int i = 0; i < COLUMNS; i++){
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
    for (int i = (ROWS-1); i > 0; i--){
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
    for (int i = 0; i < ROWS; i++){
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
    for (int i = (COLUMNS-1); i > 0; i--){
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
    for (int i = 0; i < COLUMNS; i++){
        if (column[i+1] == column[i]){
            column[i+1] += column[i];
            column[i] = 0;
        }
    }
    return column;
}

void mergeColumn(int matrix[ROWS][COLUMNS], int column[COLUMNS], int index){
        for (int i = 0; i < COLUMNS; i++){
            //Get first index of all rows
            matrix[i][index] = column[i]; 
        }
}

// 4222

/*
 * Params: 2D Array, String Direction
 * Return: Depends on Direction
 */

void merge(int matrix[ROWS][COLUMNS], int direction){
    //Merging Right = 1
    //Merging Left = 2
    //Merging Up = 3
    //Merging Down = 4
    if (direction == 1){
        for (int i = 0; i < ROWS; i++){
            int *row = getRow(matrix, i);
            mergeRight(row);
        }
    }

    if (direction == 2){
        for (int i = 0; i < ROWS; i++){
            int *row = getRow(matrix, i);
            mergeLeft(row);
        }
    }

    if (direction == 3){
        int columnArr[COLUMNS];
        for (int i = 0; i < COLUMNS; i++){
            getColumn(matrix, i, columnArr);
            mergeUp(columnArr);
            mergeColumn(matrix, mergeUp(columnArr), i);
        }
    }

    if (direction == 4){
        int columnArr[COLUMNS];
        for (int i = 0; i < COLUMNS; i++){
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

    //printf("\nPRINTING COLUMNS MERGED DOWN\n");
    //merge(testGrid, 2);
    //printArray(testGrid);
    //return 0;
//}
