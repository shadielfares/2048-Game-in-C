#include <stdlib.h>
#include <stdio.h>
#include "macros.h"

void slideRight(int new_array[gridROWS][gridCOLS], int k){

	for(int r = 0; r < gridROWS; r++){
		for(int c = k; c < gridCOLS; c++){
			slideRight(new_array, c + 1);
			if(new_array[r][c + 1] == 0 && c != 3){
				new_array[r][c + 1] = new_array[r][c];
				new_array[r][c] = 0;
			}	
		}
	}
}

void slideLeft(int new_array[gridROWS][gridCOLS], int k){

        for(int r = 0; r < gridROWS; r++){
                for(int c = k; c < gridCOLS; c++){
			slideLeft(new_array, c + 1);
                        if(new_array[r][c] == 0 && c != 3){
                                new_array[r][c] = new_array[r][c + 1];
                        	new_array[r][c + 1] = 0;
			}
			
                }
        }
}

void slideUp(int new_array[gridROWS][gridCOLS], int k){

        for(int c = 0; c < gridCOLS; c++){
                for(int r = k; r < gridROWS; r++){
                        slideUp(new_array, r + 1);
                        if(new_array[r][c] == 0 && r != 3){
                                new_array[r][c] = new_array[r + 1][c];
                                new_array[r + 1][c] = 0;
                        }
                }
        }
}

void slideDown(int new_array[gridROWS][gridCOLS], int k){

        for(int c = 0; c < gridCOLS; c++){
                for(int r = k; r < gridROWS; r++){
                        slideDown(new_array, r + 1);
                        if(new_array[r + 1][c] == 0 && r != 3){
                                new_array[r + 1][c] = new_array[r][c];
                                new_array[r][c] = 0;
                        }
                }
        }
}

void slide(int array[gridROWS][gridCOLS], int direction){
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
