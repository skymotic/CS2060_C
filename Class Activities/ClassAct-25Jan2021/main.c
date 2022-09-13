// Chapter two learnings
// Format input and output
// Using if statements, relational
// operators, and equality operators
// use secure coding practices
#include <stdio.h>

// Main function demonstrates fundamental coding examples

int main( void )
{
	// Explore what the & in front of the variable does
	int test = 4; //test output
	printf("test %d\n", test);
	printf("&test %p\n", &test);
	puts( "What is the above showing?\n" );
	
	//prompt user
	// secure coding use puts when terminates with new line
	puts( "Enter two integers, and I will tell you" );
	//secure coding use %s when not terminating new line
	printf( "%s","the relationships they satisfy: " );

	int num1; // first number to be read from user
	int num2; // second number to be read from user
	
	// read two integers
	// why is the & needed
	scanf( "%d %d", &num1, &num2 ); 

	//check if numbers are equal
	if ( num1 == num2 )
	{
		printf( "%d is equal to %d\n", num1, num2 );
	} // end if

	//check if numbers are not equal
	if ( num1 != num2 )
	{
		printf( "%d is not equal to %d\n", num1, num2 );
	} // end if

	//check if first number is less than second number
	if ( num1 < num2 )
	{
		printf( "%d is less than %d\n", num1, num2 );
	} // end if

	//check if first number is greater than second number
	if ( num1 > num2 )
	{
		printf( "%d is greater than %d\n", num1, num2 );
	} // end if

	//check if first number is greater than second number
	if ( num1 <= num2 )
	{
		printf( "%d is less than or equal to %d\n", num1, num2 );
	} // end if
	
	//check if first number is greater than second number
	if ( num1 >= num2 )
	{
		printf( "%d is greater than or equal to %d\n", num1, num2 );
	} // end if
	
} // end function main
