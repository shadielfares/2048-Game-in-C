/* Kurlan Beeharry, 400521584, December 5 2024
 *
 * The slide functionality takes in a 2d array of integers and slides them in a given direction
 * It takes as input a 2d array and a integer representing the direction to slide to
 * It returns as side effect the edited array
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include "../../include/macros.h"

/* Slide Right function
 *
 * int new_array[gridRows][gridCols] = array to be used to slide integers
 * int k = represents initial value of for loop for recursive function
 *
 * Slides all integers to the right of the board
 *
 * As side effect modifies the given array
 *
 * */

void slideRight(int new_array[gridRows][gridCols], int k){

	for(int r = 0; r < gridRows; r++){
		for(int c = k; c < gridCols; c++){
			slideRight(new_array, c + 1);
			if(new_array[r][c + 1] == 0 && c != 3){
				new_array[r][c + 1] = new_array[r][c];
				new_array[r][c] = 0;
			}	
		}
	}
}

/* Slide Left function
 *
 * int new_array[gridRows][gridCols] = array to be used to slide integers
 * int k = represents initial value of for loop for recursive function
 *
 * Slides all integers to the left of the board
 *
 * As side effect modifies the given array
 *
 * */

void slideLeft(int new_array[gridRows][gridCols], int k){

        for(int r = 0; r < gridRows; r++){
                for(int c = k; c < gridCols; c++){
			slideLeft(new_array, c + 1);
                        if(new_array[r][c] == 0 && c != 3){
                                new_array[r][c] = new_array[r][c + 1];
                        	new_array[r][c + 1] = 0;
			}
			
                }
        }
}

/* Slide Up function
 *
 * int new_array[gridRows][gridCols] = array to be used to slide integers
 * int k = represents initial value of for loop for recursive function
 *
 * Slides all integers to the up of the board
 *
 * As side effect modifies the given array
 *
 * */

void slideUp(int new_array[gridRows][gridCols], int k){

        for(int c = 0; c < gridCols; c++){
                for(int r = k; r < gridRows; r++){
                        slideUp(new_array, r + 1);
                        if(new_array[r][c] == 0 && r != 3){
                                new_array[r][c] = new_array[r + 1][c];
                                new_array[r + 1][c] = 0;
                        }
                }
        }
}

/* Slide Down function
 *
 * int new_array[gridRows][gridCols] = array to be used to slide integers
 * int k = represents initial value of for loop for recursive function
 *
 * Slides all integers to the down of the board
 *
 * As side effect modifies the given array
 *
 * */

void slideDown(int new_array[gridRows][gridCols], int k){

        for(int c = 0; c < gridCols; c++){
                for(int r = k; r < gridRows; r++){
                        slideDown(new_array, r + 1);
                        if(new_array[r + 1][c] == 0 && r != 3){
                                new_array[r + 1][c] = new_array[r][c];
                                new_array[r][c] = 0;
                        }
                }
        }
}

/* Slide function
 *
 * int new_array[gridRows][gridCols] = array to be used to slide integers
 * int direction = integer representing direction of slide
 *
 * Slides all integers to the given side of the board
 *
 * As side effect modifies the given array
 *
 * */

void slide(int array[gridRows][gridCols], int direction){
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
