/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: 05
* Due: 05 April 2021, 10:55am
* Description:
* 	This program simulated the workings of a gasPump station
* 	It asks the user for nessicary information, then calculates the price and simulates
* 	the pumping. Afterwards it can print out a receipt on the users request with all the
* 	pricing, fuel and other information printer out
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void setupMode(double *reg1GasPrice, double *reg2GasPrice, double *reg3GasPrice, double *desGasPrice);
bool exitMode(unsigned const int *pin, unsigned int *totalOut, double *totalIncome);
void discountCard(char *haveDiscountCard);
void carWash(char *wantCarWash, unsigned int *carWashType, unsigned int *carWashPin);
void creditCard(unsigned int *zipCode);
void fuelGrade(unsigned int *fuelGradeType);
void receipt(char *wantReceipt, const double *reg1, const double *reg2, const double *reg3, const double *des, unsigned int *fuelDisp, char *wantCarWash, unsigned int *carWashType, double *totalFuelPrice, double *totalPrice, const unsigned int *pin, char *haveDiscountCard, unsigned int *fuelGradeType);
double calcFuelPrice(const double *reg1, const double *reg2, const double *reg3, const double *des, char *haveDiscountCard, unsigned int *fuelGradeType);
void fuel(const double *reg1, const double *reg2, const double *reg3, const double *des, char *haveDiscountCard, char *wantCarWash, unsigned int *carWashType, double *totalFuelPrice, double *totalPrice, unsigned int *fuelGradeType, unsigned int *fuelDisp);
void varInput(char *x, char str[]);
void switchBlock(double *fuelPrice, const double *fuel, char *haveDiscountCard);
void printReceipt(const double *reg1, const double *reg2, const double *reg3, const double *des, unsigned int *fuelDisp, char *wantCarWash, unsigned int *carWashType, double *totalFuelPrice, double *totalPrice, const unsigned int *pin, char *haveDiscountCard, unsigned int *fuelGradeType);
void empty(double *totalPrice, double *totalFuelPrice);

int main(int argc, char *argv[]) {
	
	// Variables start
	double totalIncome, totalPrice, totalFuelPrice = 0;

	//mass creation of vars
	char haveDiscountCard, wantCarWash, wantReceipt;
	unsigned int carWashType, carWashPin, zipCode, fuelGradeType, fuelDisp, totalOut = 0;
	const unsigned int pin = 2445;
	
	//creates temporary pre-varablies before setting them to a secured constant var
	double preg1GasPrice, preg2GasPrice, preg3GasPrice, pdesGasPrice;
	setupMode(&preg1GasPrice, &preg2GasPrice, &preg3GasPrice, &pdesGasPrice);
	const double reg1GasPrice = preg1GasPrice;
	const double reg2GasPrice = preg2GasPrice;
	const double reg3GasPrice = preg3GasPrice;
	const double desGasPrice = pdesGasPrice;
	// Variables end
	
	//Will run the code continuously until exit code is entered
	while(true){
		
		//set the random seed to the time of the program start
		srand(time(0));
		//calcs the amount of fuel that will be dispensed
		fuelDisp = (rand() % 30) + 1;
		
		puts("***************************");
		puts("Welcome to Gas Station 2060");
		puts("***************************");
		
		//asks if user has discount card
		discountCard(&haveDiscountCard);
		
		//checks to see if exit key is entered
		if(haveDiscountCard == 'q' || haveDiscountCard == 'Q'){
			if(exitMode(&pin, &totalOut, &totalIncome)) {break;}
			puts("Wrong pin, resuming with no discount\n\n");
		}
		
		//for all the methods bellow, please see top of each for desc
		carWash(&wantCarWash, &carWashType, &carWashPin);
		creditCard(&zipCode);
		fuelGrade(&fuelGradeType);
		fuel(&reg1GasPrice, &reg2GasPrice, &reg3GasPrice, &desGasPrice, &haveDiscountCard, &wantCarWash, &carWashType, &totalFuelPrice, &totalPrice, &fuelGradeType, &fuelDisp);
		receipt(&wantReceipt, &reg1GasPrice, &reg2GasPrice, &reg3GasPrice, &desGasPrice, &fuelDisp, &wantCarWash, &carWashType, &totalFuelPrice, &totalPrice, &carWashPin, &haveDiscountCard, &fuelGradeType);
		
		//keeps log of the total values for when machine is exited
		totalOut += fuelDisp;
		totalIncome += totalPrice;
		
		//clears some variables for next run
		empty(&totalPrice, &totalFuelPrice);
		
	}
	
	return 0;
}

//Asks fuel attendent to enter in the prices of each type of fuel 
void setupMode(double *reg1, double *reg2, double *reg3, double *des){
	double temp;
	
	puts("------------\nSetup Mode\n------------");
	puts("\nPlease enter the price of the Regualr Unlead Fuel: ");
	scanf(" %lf", &temp);
	*reg1 = temp;
	puts("");
	
	puts("\nPlease enter the price of the MidGrade Unlead Fuel: ");
	scanf(" %lf", &temp);
	*reg2 = temp;
	puts("");
	
	puts("\nPlease enter the price of the Premium Unlead Fuel: ");
	scanf(" %lf", &temp);
	*reg3 = temp;
	puts("");
	
	//-----------------------------
	
	puts("\n\nPlease enter the price of Diesel Fuel: ");
	scanf(" %lf", &temp);
	*des = temp;
	
	printf("The price of Regular Unlead fuel has been set to: $%.2lf\n", *reg1);
	printf("The price of Mid-grade Unlead fuel has been set to: $%.2lf\n", *reg2);
	printf("The price of Premium Unlead fuel has been set to: $%.2lf\n", *reg3);
	printf("The price of Diesel fuel has been set to: $%.2lf\n", *des);
	puts("------------------\nExiting Setup Mode\n------------------\n");
}

//If acticated, asks user for exit pin, and if pin is correct, will return true
bool exitMode(unsigned const int *pin, unsigned int *totalOut, double *totalIncome){
	unsigned int temp;
	bool tempReturn = false;
	
	puts("Please enter the pin:");
	scanf(" %d", &temp);
	if(temp == *pin){
		printf("Total fuel out: %d\nTotal Income: %.2lf", *totalOut, *totalIncome);
		tempReturn = true;
	}
	return tempReturn;
}

//asks user if they have a discount card (With error checking)
void discountCard(char *haveDiscountCard){
	while(true){
		puts("Do you have a discount card? (y/n)");
		scanf(" %c", haveDiscountCard);
		
		if((*haveDiscountCard == 'y' || *haveDiscountCard == 'Y' || *haveDiscountCard == 'n' || *haveDiscountCard == 'N' || *haveDiscountCard == 'q' || *haveDiscountCard == 'Q')) {
			break;
		}
		puts("---\nInvalid input, Please try again\n---------\n");
	}
}

//Asks user if they would like a car wash using varInput (which error checks) then asks what type of car wash (With error checking)
void carWash(char *wantCarWash, unsigned int *carWashType, unsigned int *carWashPin){
	
	varInput(wantCarWash, "Would you like a CarWash? (y/n)\n");
	
	*carWashPin = (int)(( rand() % 9999 ) + 1);
	
	if(*wantCarWash == 'y' || *wantCarWash == 'Y'){
		puts("---\nWhat type of car wash would you like?\n\t1.) Basic : $2.00\n\t2.) Premium : $5.00\n\t3.) Platinum : $8.00");
		scanf("%d", carWashType);
		if(!(*carWashType == 1 || *carWashType == 2 || *carWashType == 3)){
			puts("Invalid Input, Please try again\n\n");
			carWash(wantCarWash, carWashType, carWashPin);
		}
		printf("Your car wash pin is: %d\n\n", *carWashPin);
	}
}

//simulates user swiping card, then asks for zip code
void creditCard(unsigned *zipCode){
	puts("Please swipe your credit card\nWaiting.......\nProcessing.......\nPlease Enter your Zip-Code:");
	scanf(" %d", zipCode);
	if(!(*zipCode > 10000 && *zipCode < 99999)){
		puts("Invalid input, please try again");
		creditCard(zipCode);
	}
	puts("Authorized!\n");
}

//Aks user what type of fuel they would like (Has error Checking)
void fuelGrade(unsigned int *fuelGradeType){
	while(true){
		puts("Please select fuel grade:\n\t1.) Regular Unlead Fuel\n\t2.) Mid-Grade Unlead Fuel\n\t3.) Premium Unlead Fuel\n\t4.) Diesel Fuel");
		scanf(" %d", fuelGradeType);
		
		if(*fuelGradeType == 1 || *fuelGradeType == 2 || *fuelGradeType == 3 || *fuelGradeType ==4){
			break;
		}
		puts("Invalid Input, Please try again");
	}
}

//Asks user if they would like Receipt, uses varInput method for error checking
void receipt(char *wantReceipt, const double *reg1, const double *reg2, const double *reg3, const double *des, unsigned int *fuelDisp, char *wantCarWash, unsigned int *carWashType, double *totalFuelPrice, double *totalPrice, const unsigned int *pin, char *haveDiscountCard, unsigned int *fuelGradeType){
	
	varInput(wantReceipt, "Would you like a receipt? (y/n)\n");
	
	if(*wantReceipt == 'y' || *wantReceipt == 'Y'){
		//calls method to print the receipt
		printReceipt(reg1, reg2, reg3, des, fuelDisp, wantCarWash, carWashType, totalFuelPrice, totalPrice, pin, haveDiscountCard, fuelGradeType);
	}
}

//Takes in all the information in entered so far to calculate the price of the fuel for the current user, returns the calculated fuel price
double calcFuelPrice(const double *reg1, const double *reg2, const double *reg3, const double *des, char *haveDiscountCard, unsigned int *fuelGradeType){
	
	double fuelPrice = 0;
	switch(*fuelGradeType){
		//switch block is used to reduce redundent code
		case 1 : switchBlock(&fuelPrice, reg1, haveDiscountCard);break;
		case 2 : switchBlock(&fuelPrice, reg2, haveDiscountCard);break;
		case 3 : switchBlock(&fuelPrice, reg3, haveDiscountCard);break;
		case 4 : switchBlock(&fuelPrice, des, haveDiscountCard);break;
	}
	return fuelPrice;
}

//uses calcFuelPrice, then shows the fueling with the price for each gallon displaed
void fuel(const double *reg1, const double *reg2, const double *reg3, const double *des, char *haveDiscountCard, char *wantCarWash, unsigned int *carWashType, double *totalFuelPrice, double *totalPrice, unsigned int *fuelGradeType, unsigned int *fuelDisp){
	
	double fuelPrice = calcFuelPrice(reg1, reg2, reg3, des, haveDiscountCard, fuelGradeType);
	
	puts("-----------Fueling-----------");
	for(int x = 0; x < *fuelDisp; x++){
		*totalFuelPrice += fuelPrice;
		printf("**$%-10.2lf%6d Gallons**\n", *totalFuelPrice, x+1);
	}
	
	if(*wantCarWash == 'y' || *wantCarWash == 'Y'){
		switch(*carWashType){
			case 1 : *totalPrice += 2;break;
			case 2 : *totalPrice += 5;break;
			case 3 : *totalPrice += 8;break;
		}
	}
	*totalPrice += *totalFuelPrice;
}

//sets a provided varable, then error checks and re-runs if error is detected (can only do yes/no checking)
void varInput(char *x, char str[]){
	while(true){
		printf("%s", str);
		scanf(" %c", x);
		if(*x == 'y' || *x == 'Y' || *x == 'n' || *x == 'N'){
			break;
		}
		puts("Invalid Input, Please try again\n");
	}
}

//Calculates fuel price dependent of discount card
void switchBlock(double *fuelPrice, const double *fuel, char *haveDiscountCard){
	switch(*haveDiscountCard){
		case 'y' : *fuelPrice = *fuel - 0.03;break;
		case 'Y' : *fuelPrice = *fuel - 0.03;break;
		case 'n' : *fuelPrice = *fuel;break;
		case 'N' : *fuelPrice = *fuel;break;
	}
}

//Takes in all the information through out the program and displays it to the user.
void printReceipt(const double *reg1, const double *reg2, const double *reg3, const double *des, unsigned int *fuelDisp, char *wantCarWash, unsigned int *carWashType, double *totalFuelPrice, double *totalPrice, const unsigned int *pin, char *haveDiscountCard, unsigned int *fuelGradeType){
	
	double fuelType = calcFuelPrice(reg1, reg2, reg3, des, haveDiscountCard, fuelGradeType);
	
	//Shows how many gallons were pumped, price per gallon, and cost of fuel
	puts("**********Receipt**********");
	printf("Gallons:\t\t%d/gal\nPrice/Gallon:\t\t$%.2lf\nFuel Cost:\t\t$%.2lf\n", *fuelDisp, fuelType, *totalFuelPrice);
	
	
	//If statments checking if there was a car wash, and what type. Then printing pin.
	if((*wantCarWash == 'y' || *wantCarWash == 'Y') && *carWashType == 1){
		printf("car Wash:\t\t$2.00\t(pin: %d)\n", *pin);
	}
	
	else if((*wantCarWash == 'y' || *wantCarWash == 'Y') && *carWashType == 2){
		printf("car Wash:\t\t$5.00\t(pin: %d)\n", *pin);
	}
	
	else if((*wantCarWash == 'y' || *wantCarWash == 'Y') && *carWashType == 3){
		printf("car Wash:\t\t$8.00\t(pin: %d)\n", *pin);
	}
	
	//prints out total price; fuel price + anything else (Car wash)
	puts("----------------------------");
	printf("Total:\t\t\t$%.2f\n", *totalPrice);
	puts("***************************\n");
	puts("Thank You for Your Business!\n");
	puts("***************************\n\n");
}

//Emptys out a few varables
void empty(double *totalPrice, double *totalFuelPrice){
	*totalPrice = 0;
	*totalFuelPrice = 0;
}

