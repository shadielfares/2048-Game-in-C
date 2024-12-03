#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/scoring.h"

void initHighScore(){
	FILE *file;
	char *fileName = "highscore.txt";
	
	file = fopen(fileName, "w");

	for(int i = 0; i < 10; i++){
		fputs("0\n", file);
	}
	
	fclose(file);
}

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
