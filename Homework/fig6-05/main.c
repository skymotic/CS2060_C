#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initalizeArray(unsigned int numArray[]);
void displayArray(const unsigned int numArray[]);
unsigned int largestElem(const unsigned int numArray[]);
unsigned int sumElems(const unsigned int numArray[]);
unsigned int average(const unsigned int numArray[]);
void bubbleSort(unsigned int numArray[]);

int length = 0;

int main(int argc, char *argv[]) {
	
	int numbers[LENGTH] = {1,2,3,4,5,6,7,8,9,10};
	int sumNum = 0;
	
	puts("how long would you like the array?");
	scanf("%d", &length);
	
	
	
	//initializeArray(numbers);
	puts("origonal Array");
	displayArray(numbers);
	sumNum = sumElems(numbers);
	printf("\n%Sum is%d\n", sumNum);
	printf("Largets number: %d\n", largestElm(numbers));
	puts("Sorted Array");
	bubbleSort(numbers);
	displayArray(numbers);
	printf("The average for sum of the numbers is: %d\n", average(numbers));
	
	
	return 0;
}

void initalizeArray(unsigned int numArray[]){
	//numArray[LENGTH] = {};
}

void displayArray(const unsigned int numArray[]){
	int x;
	for(x = 0; x < length; x++){
		printf("%d ", numArray[x]);
	}
}

unsigned int largestElem(const unsigned int numArray[]){
	int largest = numArray[0];
	int x;
	for( x = 0; x < length; x++){
		if(numArray[x] > largest){
			largest = numArray[x];
		}
	}
	return largest;
}

unsigned int sumElems(const unsigned int numArray[]){
	unsigned int sum = 0;
	int x;
	for(x = 0; x < length; x++){
		sum += numArray[x];
	}
	return sum;
}

unsigned int average(const unsigned int numArray[]){
	unsigned int sum = 0;
	int x;
	for(x = 0; x < length; x++){
		sum += numArray[x];
	}
	return sum/length;
}

void bubbleSort(unsigned int numArray[]){ 
	int temp = 0;
	int i,j;
   	for (i = 0; i < length-1; i++) {
       	// Last i elements are already in place    
       	for (j = 0; j < length-i-1; j++) {
           if (numArray[j] > numArray[j+1]) {
           		temp = numArray[j];
           		numArray[j]=numArray[j+1];
           		numArray[j+1] = temp;
          	}
      	}
    }
}
