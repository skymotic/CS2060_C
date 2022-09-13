/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: 06
* Due: 13 April 2021, 10:55am
* Description:
* 	This program randomly generates scetences and then outputs
* 	them to a file labled: output.txt
* 	It uses a 2d array of randomly generated digits for each and
* 	every word generated and corisponds it to a word in the arrays
* 	that store the pre-determined words.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//change the number of scentences
#define NUMSEN 20
/*
*	Definatly did 40,000, files was 2MB and it took .05 seconds to run :D
*	It would have taken me like 10 minutes to scroll to the bottom. (-_-)
*/


int getArrSize(char** str);
char *strcat(char *dest, const char *src);

int main(int argc, char *argv[]) {
	//Stores all the words than can be used for a scentence
	char* articlePtr[6] = {"them", "a", "one", "some", "any"};
	char* nounPtr[6] = {"baby", "bunny", "dog", "town", "car"};
	char* verbPtr[6] = {"drove", "jumped", "ran", "walked", "skipped"};
	char* prepositionPtr[6] = {"to", "form", "over", "under", "on"};
		/*------- article, noun, verb, perposition, article, noun -------*/

	//generates a 2d array of rand nums. Each number corilates to a random word for EACH scentence.
	int randoNums[NUMSEN][6];
	
	//Initializing the random
	time_t t;
	srand((unsigned) time(&t));
	
	int x, y;
	
	//Embeded forloop that will generate a total of 120(20x6) random numbers between 0 - 4
	for(y=0; y<NUMSEN; y++){
		for(x=0; x<6; x++){
			randoNums[y][x] = rand() % 5;
		}
	}
	
	//opens the file 'output.txt' as a writable
	FILE *ff = fopen("output.txt", "w");
	puts("Opened File");
	puts("Starting Printing to file");
	
	//loops 20 times to create 20 scentences, prints each word to file seperatly with spaces, capitals and periods
	for(x=0; x<NUMSEN; x++){
		
		//prints each line to file.
		fprintf(ff, "%c%s ", toupper(*articlePtr[randoNums[x][0]]), articlePtr[randoNums[x][0]]+1);
		fprintf(ff, "%s ", nounPtr[randoNums[x][1]]);
		fprintf(ff, "%s ", verbPtr[randoNums[x][2]]);
		fprintf(ff, "%s ", prepositionPtr[randoNums[x][3]]);
		fprintf(ff, "%s ", articlePtr[randoNums[x][4]]);
		fprintf(ff, "%s.\n", nounPtr[randoNums[x][5]]);
		
	}
	
	//closes file
	fclose(ff);
	puts("Done Printing to file\nClosing File");
}
