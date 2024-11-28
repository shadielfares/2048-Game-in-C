#include <stdlib.h>
#include <stdio.h>

#define ROWS 4
#define COLS 4

void slideRight(int new_array[ROWS][COLS], int k){

	for(int r = 0; r < ROWS; r++){
		for(int c = k; c < COLS; c++){
			slideRight(new_array, c + 1);
			if(new_array[r][c + 1] == 0 && c != 3){
				new_array[r][c + 1] = new_array[r][c];
				new_array[r][c] = 0;
			}	
		}
	}
}

void slideLeft(int new_array[ROWS][COLS], int k){

        for(int r = 0; r < ROWS; r++){
                for(int c = k; c < COLS; c++){
			slideLeft(new_array, c + 1);
                        if(new_array[r][c] == 0 && c != 3){
                                new_array[r][c] = new_array[r][c + 1];
                        	new_array[r][c + 1] = 0;
			}
			
                }
        }
}

void slideUp(int new_array[ROWS][COLS], int k){

        for(int c = 0; c < COLS; c++){
                for(int r = k; r < ROWS; r++){
                        slideUp(new_array, r + 1);
                        if(new_array[r][c] == 0 && r != 3){
                                new_array[r][c] = new_array[r + 1][c];
                                new_array[r + 1][c] = 0;
                        }
                }
        }
}

void slideDown(int new_array[ROWS][COLS], int k){

        for(int c = 0; c < COLS; c++){
                for(int r = k; r < ROWS; r++){
                        slideDown(new_array, r + 1);
                        if(new_array[r + 1][c] == 0 && r != 3){
                                new_array[r + 1][c] = new_array[r][c];
                                new_array[r][c] = 0;
                        }
                }
        }
}

void slide(int array[ROWS][COLS], int direction){
	if(direction == 1){
		slideRight(array, 0);	
	} else if(direction == 2){
		slideLeft(array, 0);
	} else if(direction == 3){
		slideUp(array, 0);
	} else if(direction == 4){
		slideDown(array, 0);
	}

}
