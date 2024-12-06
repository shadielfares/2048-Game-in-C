/* Kurlan Beeharry, 400521584, December 5 2024
 *
 * The highscore function handles all highscore I/O to a txt file
 * It takes in a score and places it in the correct spot in the highscore list
 * It writes to the txt file to the new list of highscores
 *
 * */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/scoring.h"

/*
 * Initialize highscore function
 *
 * No Parameters
 *
 * Creates a initial highscore txt file if not created
 *
 * Writes to the txt file an initialized array of highscores
 *
 * */

void initHighScore(){
	FILE *file;
	char *fileName = "highscore.txt";
	
	file = fopen(fileName, "w");

	for(int i = 0; i < 10; i++){
		fputs("0\n", file);
	}
	
	fclose(file);
}

/*
 * Highscore function
 *
 * Parameters:
 * int score = Score obtained by current after current session
 *
 * Verifies if score is highscore, if yes adds it to the correct spot
 *
 * Writes to the file the new array of highscores
 *
 * */

void highscore(int score){
	int highscores[10] = {0};
	int new_highscore[10] = {0};

	readFile(highscores);

	int i = 0;	
	bool insert = false;

	for(int j = 0; j < 10; j++){
		if(!insert && score > highscores[i]){
			new_highscore[j] = score;
			insert = true;
		} else {
			new_highscore[j] = highscores[i];
			i++;
		}
	}

	writeFile(new_highscore);
}

/*
 * Read File function
 *
 * Parameters:
 * int highscores[10] = array of 10 integers representing the highscores 
 *
 * Reads from file to obtain data for highscores
 *
 * Modifies array with data obtained from file
 *
 * */

void readFile(int highscores[10]){
	FILE *file;
        char *fileName = "highscore.txt";
        file = fopen(fileName, "r");

        if(file == NULL){
                fprintf(stderr, "Cannot open file\n");
                return;
        }

        char strNum[1000];
        int i = 0;

        while(fgets(strNum, sizeof(strNum), file) != NULL && i < 10){
                highscores[i] = atoi(strNum);
                i++;
        }

        fclose(file);
}

/*
 * Write File function
 *
 * Parameters:
 * int highscores[10] = array of 10 integers representing the highscores
 *
 * Writes to file the newly modified highscore list
 * 
 * */

void writeFile(int new_highscore[10]){
	FILE *file;
	char *fileName = "highscore.txt";
	file = fopen(fileName, "w");

        if(file == NULL){
                fprintf(stderr, "Cannot open file\n");
        }

        for(int j = 0; j < 10; j++){
                fprintf(file, "%d\n", new_highscore[j]);
        }

        fclose(file);
}
