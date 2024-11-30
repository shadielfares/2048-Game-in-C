#include <stdlib.h>
#include <stdio.h>

#include "../../include/scoring.h"

void score(){

}

void highscore(int score){
	FILE *file;
	char *fileName = "./highscore.txt";

	if((file = fopen(fileName, "r")) == NULL){
		fprintf("stderr, Cannot open file");
		return ;
	}

	int highscores[10] = {0};
	int i = 0;

	while(!feof(file)){
		fgets(highscores[i], sizeof(int), file);
		i++;
	}
	
	for(int j = 0; j < 10; j++){
		if(){
		
		}
	}

	fclose(file);
}

void printHighscore(){

}

int main(){

}
