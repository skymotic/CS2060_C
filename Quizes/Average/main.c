#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int inputA = (-6);
	int inputB = (-2);
	
	int result = 0;
	
	for(int x = (inputA); x< (inputA) + abs((inputA)-(inputB)); x++){
		result += x;
	}
	
	printf("%s %d", "The sum of all number between -6 and -2 is:", result);
	return 0;
}
