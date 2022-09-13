/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: Quiz-3 Project
* Due: 2 May 2021, 11:58 PM
* 
* Project Type: Polling
* 
* Description:
* 	This program takes in a .CSV file that was printed from poll data.
* 	The data is then put into an array structur where it can then be computed
* 	into averages, max, and mins.
*/


//Included packages
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//PreCall
void parseCSV(FILE *file, FILE *temp, char **questions);
void getDataSize(FILE *file, int *row, int *colum);
void calcStats(FILE *temp, char **questions, int row, int col);
int findMin(int *ary, int row);
int findMax(int *ary, int row);
double findAv(int *ary, int row);
void printReport(char **questions, double average, int max, int min, int line);
void avReport(char **questions, double average, char x, int index);
int findMinAv(double *ary, int col);
int findMaxAv(double *ary, int col);

//Main
int main(int argc, char *argv[]) {
	
	//Files that are being opened
	FILE *fp = fopen("data.csv", "r");
	FILE *fp2 = fopen("temp.data", "w");
	
	//Gets and stores the amount of quesions, and responses
	//	questions = dataColum, reponses = dataRow
	int dataRow = 0, dataColum = 0;
	getDataSize(fp, &dataRow, &dataColum);
	
	//creates an array to hold all the questions using the data from dataColum
	char *questions[dataColum];
	
	//calls on the parseCSV to extract the data from the file
	parseCSV(fp, fp2, questions);
	
	//Calls on calcStats to figure out the stats of each question
	calcStats(fp2, questions, dataRow, dataColum);
	
	//removes the temporary file
	remove("temp.data");
	//closes .csv file
	fclose(fp);
}

void parseCSV(FILE *file, FILE *temp, char **questions){
	
	/*
	* This method removes the unessicary data from the .csv file and stores
	* the perternat data in a temp file.
	* It also put the data in a more easy format to read into the program
	*/
	
	//a buffer to store 1 line at a time
	char buffer[1028];
	
	//counter for how many lines have been read
	int counter = 0;
	
	//While there is another line to read
	while(fgets(buffer, sizeof(buffer), file)){
		
		//token stores the data between the commas temporarily
		char *token;
		
		//readys how many fields have been ready in from the line
		int counterIN = 0;
		
		//tells the program to look at the commas on the buffer
		token = strtok(buffer, ",");
		//moves past the un-nessicary information
		token = strtok(NULL, ",");
		
		//While there is another field on the line to ready
		while(token != NULL){
			//if it is the first line
			if(counter == 0){
				//reads in the questions, which are stored on the first line
				
				//allocates the exsact amount of space needed to store the token
				questions[counterIN] = (char *) malloc(sizeof('\0') * strlen(token));
				//copys the token into a place in memory, that is being pointed to by questions.
				strcpy(questions[counterIN], token);
			}
			// If it is NOT the first like
			else{
				//Stores numerical data in temp file, seperated by space
				fprintf(temp, "%d ", atoi(token) );
			}
			
			//sets the token to the next field
			token = strtok(NULL, ",");
			counterIN = counterIN + 1;
		}
		
		//moves the line down in the temp file to more easily read it later
		if(counter != 0){
			fprintf(temp, "\n");
		}
		counter++;
	}
}

void getDataSize(FILE *file, int *row, int *colum){
	
	/*
	* This method moves past the data that is not needed
	* Then gets the size of the needed data before reseting the file
	*/
	
	//buffer to store entire 1 line at a time from file
	char buffer[1024]; int x;
	while(fgets(buffer, sizeof(buffer), file)){
		*row = *row + 1;
	}
	for(x=0; x<strlen(buffer); x++){
		if(buffer[x] == ','){
			*colum = *colum + 1;
		}
	}
	*row = *row - 1;
	rewind(file);
}

void calcStats(FILE *temp, char **questions, int row, int col) {
	
	/*
	* Reads in all collected data into a 2d array from temp file
	* Then rearrenges the data to be easily sent through a cobination
	* of methods to mind the Min, Max, and average of each question
	*/
	
	//closes out the file, then re-opens it for reading
	fclose(temp);
	temp = fopen("temp.data", "r");
	
	int max, min, x, y;
	double average[col];
	int data[row][col];
	
	//Reads in all the data from the temp file and moves it into the 2d array
	for(x=0; x<row; x++){
		for(y=0; y<col; y++){
			fscanf(temp, "%d", &data[x][y]);
		}
	}
	//closes out the temp file
	fclose(temp);
	
	//runs for the amount of questions there are, denotated by col
	for(x=0; x<col; x++){
		
		//creates a temp array and hold the entire row while calculations are done
		int temp[row];
		for(y=0; y<row; y++){
			temp[y]=data[y][x];
		}
		
		//Runs different methods to calculate the different statistics
		min = findMin(temp, row);
		max = findMax(temp, row);
		average[x] = findAv(temp, row);
		
		//Prints out the final report and an easy to read format 
		printReport(questions, average[x], max, min, x);
	}
	printf("%d\n", findMinAv(average, row));
	avReport(questions, average[findMinAv(average, row)], 'l', findMinAv(average, row));
	avReport(questions, average[findMaxAv(average, row)], 'h', findMaxAv(average, row));
}

//Scans through the array to find the smallest number
int findMin(int *ary, int row){
	int lowest = ary[0];
	for(int x = 0; x<row; x++){
		if(ary[x] < lowest){
			lowest = ary[x];
		}
	}
	return lowest;
}

//scans through the array to find the Largest number
int findMax(int *ary, int row){
	int hightest = ary[0];
	for(int x = 0; x<row; x++){
		if(ary[x] > hightest){
			hightest = ary[x];
		}
	}
	return hightest;
}

//add the sum up of all the numbers in the array, then / them by the amount of responses
//																		Denotated by: row
double findAv(int *ary, int row){
	int sum = 0;
	for(int x = 0; x<row; x++){
		sum = sum + ary[x];
	}
	return (double)sum / row;
}

void printReport(char **questions, double average, int max, int min, int line) {
	printf("-----------------------------\n");
	
	//prints out the question number along with the question
	printf("Question #%d:\n%s\n\n", line+1, questions[line]);
	
	//prints out all the statistics from the data collected on said question.
	printf("Smallest number reported: %d\nLargest number reported: %d\n", min, max);
	printf("The Average of all reported Data: %.2lf\n", average);
	
	printf("-----------------------------\n");
}

void avReport(char **questions, double average, char x, int index) {
	
	/*
	* This method prints out a report for the highes average and lowest average, and what quesiton it was
	*/
	
	puts("**********");
	if(tolower(x) == 'l') {
		puts("The Question that had the smallest average was:");
		printf("%s\nIt had an average of: %.2lf\n", questions[index], average);
	}
	else {
		puts("The Question that had the largest average was:");
		printf("%s\nIt had an average of: %.2lf\n", questions[index], average);
	}
	puts("**********");
}

//finds the lowest average, and return the index
int findMinAv(double *ary, int col) {
	double lowest = ary[0];
	int index = 0;
	for(int x = 0; x<col; x++){
		if(ary[x] < lowest){
			lowest = ary[x];
			index = x;
		}
	}
	return index;
}

//finds the highest average and returns the index
int findMaxAv(double *ary, int col) {
	double highest = ary[0];
	int index = 0;
	for(int x = 0; x<col; x++){
		if(ary[x] > highest){
			highest = ary[x];
			index = x;
		}
	}
	return index;
}
