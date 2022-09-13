#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int totalOut = 0;
double totalIncome = 0;

double totalPrice = 0;
double totalFuelPrice = 0;
int fuelDisp;
int zipCode = 0;
char haveDiscountCard = 'f';
char wantCarWash = 'f';
int carWashType = 0;
int fuelGradeType = 0;
char wantReceipt = 'f';
int pin = 2445;

int discountCard();
int carWash();
int creditCard();
int fuelGrade();
int receipt();
double calcFuelPrice();
int fuel();
bool checker(char x);
int printReceipt();
int empty();

int main(int argc, char *argv[]) {
	
	double temp;
	
	puts("------------\nSetup Mode\n------------");
	puts("\nPlease enter the price of the unlead fuel: ");
	scanf("%lf", &temp);
	double const regGasPrice = temp;
	
	puts("\n\nPlease enter the price of the diesel fuel: ");
	scanf("%lf", &temp);
	double const desGasPrice = temp;
	
	printf("The price of Unlead fuel has been set to: $%.2f\nThe price of Diesel fuel has been set to: $%.2f\n\n", regGasPrice, desGasPrice);
	puts("------------------\nExiting Setup Mode\n------------------");
	
	while(haveDiscountCard != 'q' || haveDiscountCard != 'Q'){
		
		srand(time(0));
		fuelDisp = (rand() % 30) + 1;
		
		puts("***************************");
		puts("Welcome to Gas Station 2060");
		puts("***************************");
		
		discountCard();
		if(haveDiscountCard == 'q' || haveDiscountCard == 'Q'){
			int temp2 = 0;
			puts("Please enter the pin:");
			scanf("%d", &temp2);
			if(temp2 == pin){
				printf("Total fuel out: %d\nTotal Income: %.2lf", totalOut, totalIncome);
				break;
			}
			puts("Wrong pin, resuming with no discount\n\n");
		}
		carWash();
		creditCard();
		fuelGrade();
		fuel(regGasPrice, desGasPrice);
		receipt(regGasPrice, desGasPrice);
		
		totalOut += fuelDisp;
		totalIncome += totalPrice;
		
		empty();
		
	}
	
	return 0;
}

int discountCard(){
	puts("Do you have a discount card? (y/n)");
	scanf("%c",&haveDiscountCard);
	
	
	
	if(!(haveDiscountCard == 'y' || haveDiscountCard == 'Y' || haveDiscountCard == 'n' || haveDiscountCard == 'N' || haveDiscountCard == 'q' || haveDiscountCard == 'Q')){
		printf("Invalid input ::%c::|\t\n", haveDiscountCard);
		discountCard();
	}
	return 0;
}

int carWash(){
	puts("Would you like a car wash? (y/n)");
	scanf("%c", &wantCarWash);
	
	if(wantCarWash == 'y' || wantCarWash == 'Y'){
		puts("---\nWhat type of car wash would you like?\n\t1.) Basic : $2.00\n\t2.) Premium : $5.00");
		scanf("%d", &carWashType);
	}
	
	else if(checker(wantCarWash)){
		printf("Invalid input ::%c::|\t", wantCarWash);
		carWash();
	}
	return 0;
}

int creditCard(){
	
	puts("Please swipe your credit card\nWaiting.......\nProcessing.......\nPlease Enter your Zip-Code:");
	scanf("%d", &zipCode);
	
	if(zipCode < 10000 || zipCode > 99999){
		printf("Invalid input ::%d::|\t", zipCode);
		creditCard();
	}
	return 0;
}

int fuelGrade(){
	
	puts("Please select fuel grade:\n\t1.) Unlead Fuel\n\t2.)Diesel Fuel");
	scanf("%d", &fuelGradeType);
	
	if(!(fuelGradeType == 1 || fuelGradeType == 2)){
		printf("Invalid input ::%c::|\t", fuelGradeType);
		fuelGrade();
	}
	return 0;
}

int receipt(double reg, double des){
	
	puts("Would you like a receipt? (y/n)");
	scanf("%c", &wantReceipt);
	
	if(wantReceipt == 'y' || wantReceipt == 'Y'){
		printReceipt(reg, des);
	}
	
	else if(checker(wantReceipt)){
		printf("Invalid input ::%c::|\t", wantReceipt);
		receipt(reg, des);
	}
	return 0;
}

double calcFuelPrice(double reg, double des){
	
	double fuelPrice = 0;
	switch(fuelGradeType){
		case 1 :
			switch(haveDiscountCard){
				case 'y' : fuelPrice = reg - 0.03;break;
				case 'Y' : fuelPrice = reg - 0.03;break;
				case 'n' : fuelPrice = reg;break;
				case 'N' : fuelPrice = reg;break;
			}
			break;
		case 2 :
			switch(haveDiscountCard){
				case 'y' : fuelPrice = des - 0.03;break;
				case 'Y' : fuelPrice = des - 0.03;break;
				case 'n' : fuelPrice = des;break;
				case 'N' : fuelPrice = des;break;
			}
			break;
	}
	return fuelPrice;
}
int fuel(double reg, double des){
	
	double fuelPrice = calcFuelPrice(reg, des);
	
	puts("-----------Fueling-----------");
	for(int x = 0; x < fuelDisp; x++){
		totalFuelPrice += fuelPrice;
		printf("**$%-10.2f%6d Gallons**\n", totalFuelPrice, x);
	}
	
	if(wantCarWash == 'y' || wantCarWash == 'Y'){
		switch(carWashType){
			case 1 : totalPrice += 2;break;
			case 2 : totalPrice += 5;break;
		}
	}
	totalPrice += totalFuelPrice;
	return 0;
}

bool checker(char x){
	if(!(x == 'y' || x == 'Y' ||x == 'n' ||x == 'N')){
		return true;
	}
	return false;
}

int printReceipt(double reg, double des){
	
	double fuelType = calcFuelPrice(reg, des);
	
	puts("**********Receipt**********");
	printf("Gallons:\t\t%d\nPrice/Gallon:\t\t%.2lf\nFuel Cost:\t\t%.2lf\n", fuelDisp, fuelType, totalFuelPrice);
	
	
	if((wantCarWash == 'y' || wantCarWash == 'Y') && carWashType == 1){
		puts("car Wash:\t\t$2.00\t(pin: 1751)");
	}
	
	else if((wantCarWash == 'y' || wantCarWash == 'Y') && carWashType == 2){
		puts("car Wash:\t\t$5.00\t(pin: 1751)");
	}
	
	puts("----------------------------");
	printf("Total:\t\t\t%.2f\n", totalPrice);
	puts("***************************\n");
	puts("Thank You for Your Business!\n");
	puts("***************************\n\n");
	
	//num dispensed, price per, total fuelprice, car wash w/code, Total Cost
	return 0;
}
int empty(){
	
	totalPrice = 0;
	totalFuelPrice = 0;
	return 0;
}
