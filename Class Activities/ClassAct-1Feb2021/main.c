/* 
Ch02 Lecture 4 Memory Exercise

Description: 
Compare number types, size and memory address
Explore initialized and initialized variables                                                                                          

*/ 

//prepocessor directives
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void exploreNumberTypes(void); 
void exploreInitVariables(void); 

int main (void) 
{
	
	exploreNumberTypes();	
	exploreInitVariables();
	
} //end main

// Compare the size and memory address for different number types
void exploreNumberTypes (void)
{
	//get size of number types
	int sizeInt = sizeof(int); //store size of int
	int sizeShort = sizeof(short); //store size of short
	int sizeLong = sizeof(long); //store size of long
	int sizeUnsignInt = sizeof(unsigned int); //store size of unsigned int 
	int sizeUnsignShort = sizeof(unsigned short ); //store size of unsigned short
	int sizeUnsignLong = sizeof(unsigned long); //store size of unsigned long
	int sizeFloat = sizeof(float); //store size of bytes for double
  	int sizeDouble = sizeof(double); //store size of bytes for double 	

	//print output for type, size and memory location 
	puts( "Type\t\t | Size\t | Memory Location" );
	//print memory address of variable (&) format as pointer data type (%p) 
	printf( "int\t\t | %d\t | %p\n", sizeInt, &sizeInt );
	printf( "short\t\t | %d\t | %p\n", sizeShort, &sizeShort );
	printf( "long\t\t | %d\t | %p\n", sizeLong, &sizeLong );
	printf( "unsigned int\t | %d\t | %p\n", sizeUnsignInt, &sizeUnsignInt );
	printf( "unsigned short\t | %d\t | %p\n", sizeUnsignShort, &sizeUnsignShort );
	printf( "unsigned long\t | %d\t | %p\n", sizeUnsignLong, &sizeUnsignLong );
	printf( "float\t\t | %d\t | %p\n", sizeFloat, &sizeFloat );
	printf( "double\t\t | %d\t | %p\n\n", sizeDouble, &sizeDouble );
	
 } // end function exploreNumberTypes
 
 // Explore initialize and untialized variables
void exploreInitVariables(void)
{
	
 	// set a break point and watch initVar, uninitVar1 and uninitVar2
	int initVar = 4; //initialized varaible
	int uninitVar1; // uninitialized variable 1
	int uninitVar2; // uninitialized variable 2
		
	// Look at the outputs
	printf("initVar %d\n", initVar);
	printf("uninitVar1 %d\n", uninitVar1);
	printf("uninitVar2 %d\n", uninitVar2);
	
}//end function exploreInitVariables

