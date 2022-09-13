#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int test[5] = {1,2,3,4,5};
	int *ptr = test;
	
	printf("%d\n", *ptr);
	printf("%p\n", ptr);
	
	*++ptr;
	
	printf("\n%d\n", *ptr);
	printf("%p\n", ptr);
	return 0;
}
