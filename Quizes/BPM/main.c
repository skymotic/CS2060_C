#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int age = 0;
	
	puts("Please enter your age:\n");
	scanf("%d", &age);
	
	puts("The average maximum Heart rate for a person your age is: ");
	if(age > 0 && age <= 20){
		puts("200 BPM");
	}
	else if(age > 20 && age <= 40){
		puts("185 BPM");
	}
	else if(age > 40 && age <= 50){
		puts("170 BPM");
	}
	else if(age > 50){
		puts("160 BPM");
	}
	return 0;
}
