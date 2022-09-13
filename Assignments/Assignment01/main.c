#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: 01
* Due: 3 Feb 2021, 10:55
* Description:
* 	This program askes the user for data such as height and weight, then calculates their BMI number
* 	Becuase not everyone knows their height by inches, and I didn't want to do the math in my head, I-
* 	also added a conversion calculater that turned your height of feet and inchesinto inches. I was going- 
* 	to get into parsing the data, but I am not familiar with substrings or something similar in c yet
*/

int main(int argc, char *argv[]) {
	//The main variables necessary to the function of the program
	double weight = 0;
	double height = 0;
	
	//Do know stores the yes or no data for the first question asked in the program
	char doKnow = 'n';
	
	//This section of the program asks if you know you total height in inches
	printf("\nThis program calculates your BMI number:\n");
	printf("%s\n", "Do you know how tall you are in inches? (Y/N)");
	scanf("%c", &doKnow);
	
	//Checks to see if you selected yes, and if so asks you for your height in inches
	if(doKnow == 'y' || doKnow == 'Y'){
		printf("\n-----\n%s\n", "Please Enter your Height (In inches):");
		scanf("%lf", &height);
	}
	
	//Checks to see if you selected no, and if so asks for your height in feet and inches
	//Then it converts feet and inches into just inches and sets it to the height var
	else if(doKnow == 'n' || doKnow == 'N'){
		int feet = 0;
		int inches = 0;
		
		printf("\n-----\n%s\n%s\n", "Please enter your heigh in feet and inches according to the following:", "If I am 6 foot 5 inches, I would type 6 then press enter, then type 5 and press enter");
		scanf("%d", &feet);
		scanf("%d", &inches);
		
		height = (feet*12)+inches;
		printf("Your Entered height was: %lf inches", height);
	}	
	
	//Asks user for their weight and enters it in their weight var
	printf("\n\n-----\n%s\n", "Now Please enter your Weight (In lbs):");
	scanf("%lf", &weight);
	
	//calculates and prints out your total BMI number
	printf("\n----------------\n%s\n%lf \n", "Your calculated BMI is:", ((weight*703)/(pow(height,2))) );
	
	//Prints out the BMI Value chart in a formatted way
	printf("\n%23s\n\tBMI Values\n%23s\nUnderweight:\tLess than 18.5\nNormal:\tBetween 18.5 and 24.9\nOverweight:\tBetween 25 and 29.9\nObese\t\t30 or Greater\n", "--------------------", "--------------------");
	return 0;
}
