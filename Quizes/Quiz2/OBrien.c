#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

size_t getSize(int *arr);

int main(int argc, char *argv[]) {
	
	int score[6] = {87, 100, 75, 95, 64, 82};
	int *scorePtr = &score[0];
	int *secondScorePtr = &score[1];
	
	printf("The Sum of the two are: %d\n", *scorePtr + *secondScorePtr);
	printf("The third Element is: %d\n", *(scorePtr + 2));
	
	printf("The size of the array is: %d\n", getSize(score));
	ptrArrayManip(scorePtr, getSize(score));
	printArray(&score[0], getSize(score));
	
	return 0;
}

size_t getSize(int *arr)
{
    size_t n = sizeof(arr)/sizeof(arr[0]);
    return 6;
}

void ptrArrayManip(int *ptr, int size){
	unsigned int x;
	
	puts("Manipulating array....\n\n");
	for(x=0; x<size; x++){
		*(ptr+x) -= 7;
	}
}

void printArray(int *ptr, int size){
	unsigned int x;
	puts("Printing Array....");
	for(x=0; x<size; x++){
		printf("%d ", *(ptr + x));
	}
}
