#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
	char make[20];
	char model[20];
	int year;
	float price;
};


struct Car * newCar(char *make, char *model, int year, float price);
int findOldest(struct Car **temp, int size);
void printCar(struct Car *temp);

int main(int argc, char *argv[]) {
	
	struct Car *garrage[3];
	
	garrage[0] = newCar("BMW", "X6", 2015, 65000);
	garrage[1] = newCar("Chevy", "Corvette", 2015, 59000);
	garrage[2] = newCar("Audi", "Q7", 2009, 31000);
	
	for(int x=0; x<3; x++){
		printf("Car Number: %d\n-----\n", x+1);
		printCar(garrage[x]);
		puts("\n");
	}
	
	puts("The Oldest car is...\n-------------------");
	printCar(garrage[findOldest(garrage, 3)]);
	
	return 0;
}

struct Car * newCar(char *make, char *model, int year, float price) {
	struct Car *temp = malloc(sizeof(struct Car));
	strcpy(temp->make, make);
	strcpy(temp->model, model);
	temp->year = year;
	temp->price = price;
	
	return temp;
}

int findOldest(struct Car **temp, int size) {
	int index = 0;
	
	if(temp != NULL){
		int oldest = temp[0]->year;
		for(int x=0; x<size; x++){
			if(temp[x]->year < oldest){
				oldest = temp[x]->year;
				index = x;
			}
		}
	}
	
	return index;
}

void printCar(struct Car *temp) {
	printf("Make: %s\nModel: %s\nYear: %d\nPrice: $%.2f", temp->make, temp->model, temp->year, temp->price);
}
