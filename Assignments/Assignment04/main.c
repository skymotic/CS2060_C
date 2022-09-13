/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: 04
* Due: 15 March 2021, 10:55
* Description:
* 	This program takes in grade data from the user for different sections.
* 	ie. Class activity, Assignments, quizzes, exsams.
* 	Then the program find the final grade for the course and other data such as
* 	the minimums and maximums and prints it all out to the user
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int printArray(double *arr, int sx, int sy);
int sortAnGrade(double *grades, int sx, int sy);
int displayStats(double *grades, int sx, int sy);

int main(int argc, char *argv[]) {
	
	int sizeX = 0;
	int sizeY = 4;
	double gradeTemp = 0;
	
	puts("Please enter the number of grades you will be entering: ");
	
	//the While loops checks to make sure the value entered is above 0
	while(true){
		scanf("%d", &sizeX);
		if(sizeX > 0){break;}
		puts("That was an unvlaid input, please input a number above 0");
	}
	
	//created the main array where the grades are stored
	double grades[sizeX][sizeY];
	int x, y;
	
	puts("|-| Starting the Grade entering |-|");
	
	//Has the user enter the grades by section | Class activity, Assignments, quizzes, exsams
	for(x = 0; x < 4; x++){
		printf("%s %d\n%s\n", "Please enter the grades for row:", x, "After entering each grade, please press enter");
		for(y = 0 ; y < sizeX; y++){
			while(true){
				scanf("%lf", &gradeTemp);
				if(gradeTemp>=0 && gradeTemp<=100){break;}
				puts("That was an invlad input, please put a percentage between 0 and 100");
			}
			grades[y][x] = gradeTemp;
		}
	}
	puts("|-| Grade entering Ending |-|");
	
	//calls the functions that do the 3 tasks
	puts("What was entered:");
	printArray(&grades[0][0], sizeX, sizeY); //prints the data that was just entered
	puts("The Sorted Average of grades");
	sortAnGrade(&grades[0][0], sizeX, sizeY); //find the final grade, then sorts and prints out the data
	displayStats(&grades[0][0], sizeX, sizeY); //Find the mins, maxes, and averages, then prints it out
	
	
	return 0;
}

//This function prints out the array in a nicely formated way
int printArray(double *grades, int sx, int sy){ //sx and sy are used for the size of the 2D array
	int x, y;
	
	puts("|-| Printing |-|");
	
	//the switch checks to see if there is 4 or 5 data slots passing through and lables them acordingly
	switch (sy){
		case 4 : printf("%14s%14s%14s%14s\n", "Class Activity", "Assignments", "Quizzes", "Exams"); break;
		case 5 : printf("%14s%14s%14s%14s%14s\n", "Class Activity", "Assignments", "Quizzes", "Exams", "Final Grade"); break;
	}
	
	//prints out data in array one by one, scanning through memory using pointers
	for(x = 0; x < sx; x++){
		for(y = 0; y < sy; y++){
			printf("%13.1lf%s", *grades, "%");
			grades++;
		}
		printf("\n");
	}
	return 0;
}

//This method find the final grade, then sorts the data and sends it off to be printed
int sortAnGrade(double *grades, int sx, int sy){
	double cGrades[sx][sy+1];
	int x, y;
	
	//Creates a duplicate of the grades array, and finds the 'final Grade'
	for(x = 0; x < sx; x++){
		double sum = 0;
		for(y = 0; y < sy; y++){
			cGrades[x][y] = *grades;
			sum = sum + cGrades[x][y];
			grades++;
		}
		cGrades[x][sy] = sum/sy;
	}
	
	//bubble sort algorithum | sorts the array by row according to the value in the "final Grade" slot or index value 4
	int i, j , k;
	for (i = 0; i < sx-1; i++){  
		for (j = 0; j < sx-i-1; j++){
			if (cGrades[j][sy] < cGrades[j+1][sy]){
				double temp[sy+1];
				for(k=0; k<sy+1; k++){
					temp[k] = cGrades[j][k];
				}
				for(k=0; k<sy+1; k++){
					cGrades[j][k] = cGrades[j+1][k];
				}
				for(k=0; k<sy+1; k++){
					cGrades[j+1][k] = temp[k];
				}
			}
		}
	}
	
	printArray(&cGrades[0][0], sx, sy+1);
	
	return 0;
}

//This function find the max, min, and averages then displayes them
int displayStats(double *grades, int sx, int sy){
	int x, y;
	double *iter = grades;
	double mins[sy];
	double maxs[sy];
	double averages[sy];
	
	//This is the 'finding' of all the data (max,min,average) 
	//It used embeded for loops while scanning through memory (using pointers)
	for(x = 0; x < sy; x++){
		double tempMin = *grades;
		double tempMax = *grades;
		double tempAve = 0;
		for(y = 0; y < sx; y++){
			if(*grades < tempMin){
				tempMin = *grades;
			}
			else if(*grades > tempMax){
				tempMax = *grades;
			}
			tempAve += *grades;
			grades+=sy;
		}
		grades=iter+(x+1);
		mins[x] = tempMin;
		maxs[x] = tempMax;
		averages[x] = tempAve/sx;
	}
	
	//This part prints all the data collected above
	puts("The following is averaged data:\n");
	printf("%24s%14s%14s%14s\n", "Class Activity", "Assignments", "Quizzes", "Exams");
	printf("Averages:");
	for(x=0; x<sy; x++){
		printf("%14.1lf", averages[x]);
	}
	printf("\n");
	printf("Maximums:");
	for(x=0; x<sy; x++){
		printf("%14.1lf", maxs[x]);
	}
	printf("\n");
	printf("Minimums:");
	for(x=0; x<sy; x++){
		printf("%14.1lf", mins[x]);
	}
	printf("\n");
	
	return 0;
}
