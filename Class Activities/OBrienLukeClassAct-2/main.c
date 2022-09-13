#include <stdio.h>
#include <stdlib.h>
#define MAX_LIMIT 254

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) { // ----------- Main (void)

	char input[MAX_LIMIT];
	printf("%s\n\n", "Please type anything youd like below: ");
	fgets(input, MAX_LIMIT, stdin);
	printf("%s%s", "You typed: " , input);
	return 0;
}
