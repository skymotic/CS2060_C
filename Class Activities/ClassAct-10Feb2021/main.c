/*
Name
Class activty

Description: Calculate Sales
*/

//preprocessor directives
#include <stdio.h>
#include <stdio.h>


int main()
{
	//initialize variables
	int product = 1; // current product number
	int quantity; // quantity of current product sold
	double total = 0.0; // current total retail value
	
	// prompt for item and quantity input
    puts("Enter pairs of item numbers and quantities.");
	puts("Enter -1 for the item number to end input.");
	puts("Enter product number 1-5 followed by quantity.");
	puts("Enter -1 when finished.\n");
	
	//get product number
	printf("%s", "Product Number: ");
	scanf("%d", &product);
	

	// loop while sentinel value not read from user
	while (product != -1)
	{
		//Get quantity
		printf("%s", "Quantity Number: ");
		scanf("%d", &quantity);

		// determine product then calculate total 
		switch (product){
		
			case 1:
				total+= (2.98*quantity);
				break;
			case 2: 
				total+= (4.50*quantity);
				break;
			case 3: 
				total+= (9.98*quantity);
				break;
			case 4: 
				total+= (4.49*quantity);
				break;
			case 5: 
				total+= (6.87*quantity);
				break;
			default:
				puts("Invalid product number, please re-enter");
				break;
	}
		
		//get next product 
		printf("%s", "\nProduct Number: ");
		scanf("%d", &product); // get next input
	}

	// display total retail value
	printf("\n The total retail value for one day was:  %.2f\n", total);

	return 0;
}

