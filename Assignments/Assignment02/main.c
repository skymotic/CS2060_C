#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: 02
* Due: 11 Feb 2021, 10:55
* Description:
* 	The program takes imput from the user, asking for a binary value
* 	Then the proram does some mathmatical opperations to convert the
* 	binary number into a decimal number. It then prints out the result
* 	of the decimal number and then shows what the ASCII equivelent is
*/

int main(int argc, char *argv[]) {
	
	//Gobal variables-----
	int binNum = 0; //Binary Number :: input
	int track = 0; //Keep Track of while loop
	int decNum = 0; // Decimal number :: output :: End-case
	
	//Asks uer for the binary value and then prompts for input
	puts("Please enter the binary number youd like to convert into decimal:\n");
	scanf("%d", &binNum);
	
	//Chekcs to see if the input is less than 8 digits (Length of binary bit)
	if(binNum > 99999999){
		puts("Please enter a valid Binary bit:\n::\tERROR");
	}
	
	//Mathy part that conversts binary to decimal
	while(binNum!=0 && decNum<256){
		int temp;
		track++; //increment each time while runs, keeps track of what place the calculation is at on the binary value
		temp = binNum % 10; //Checks to see if last numner is non-zero or zero, then stores in temp
		binNum /= 10; // Gets right of the far most placevalue in program
		
		//uses value in temp to check if last number was zero or non-zero
		if(temp!=0){
			decNum += (pow(2,track)/2); // If non-zero, then add place value on binary bit
		}
	}
	
	//Checks to see if number is expected
	if(decNum < 256) { 
		// Prints out value if numbers are in expected range
		printf("%s\n|\n::\t%d\n%s\n|\n::\t%c", "The Decimal value of the entered binary", decNum, "Equivelent to", decNum);
	}
	// If decNum is not in expected range, then prints out error
	else{
		puts("|\n::\tERROR\n|\nThe Value you entered was not a propper binary Value");
	}

	
	return 0;
}
