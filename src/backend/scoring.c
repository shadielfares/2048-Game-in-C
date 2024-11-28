#include <stdlib.h>
#include <stdio.h>

#define ROWS 4
#define COLS 4

#include "scoring.h"

void score(){
}
void highscore(int score){
	char *fileName = "./highscore.txt";
	FILE *file = fopen(fileName, "r");

	if(file == NULL){
		createFile("highscore.txt");
	} else {
		fclose(file);
	}

	int *scores;
	scores = readFile(fileName);
	
	for(int i = 0; i < 10; i++){
		if(scores[i] < score){
			scores[i] = score;
			break;
		}
	}

	writeFile(fileName, scores);
}

void createFile(char *name){
	FILE *file;
	file = fopen(name, "w");
	fclose(file);	
}

int *readFile(char *fileName){
	FILE *file;
	static int scores[10];

	file = fopen(fileName, "r");

	if(file == NULL){
		fprintf(stderr, "Error opening file\n");
		return scores;
	}
	
	char *buffer;
	int index = 0;
	while(fgets(buffer, sizeof(int), file) != NULL){
		int score;
		if(sscanf(buffer, "%d", &score) != EOF){
			scores[index] = score;
			index++;
		} else {
			break;
		}
	}

	fclose(file);
	return scores;
}

void writeFile(char *fileName, int scores[10]){
	FILE *file;

	file = fopen(fileName, "w");

        if(file == NULL){
                fprintf(stderr, "Error creating file\n");
                return ;
        }
	
	for(int i = 0; i < 10; i++){
		fprintf(file, "%d\n", scores[i]);
	}

	fclose(file);
}

void printHighscore(){
	char *fileName = "./highscores.txt";
	int *scores = readFile(fileName);
	
	puts("HIGHSCORES\n");
	for(int i = 0; i < 10; i++){
		printf("%d\n", scores[i]);
	}
}

int main(){
	highscore(1);
	printHighscore();
}
