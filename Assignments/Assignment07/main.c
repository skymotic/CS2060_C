/*
* Name: Luke O'Brien
* Class Name: CS2060 - Programing with C
* Class Section: 002
* Assignment: 007
* Due: 6 May 2021, 10:50 AM
* 
* Description:
* 	This program creates a linked list structure
* 	Then stores 5 pet names and ages inside.
* 	Then it will ask to remove two pets, identifying them
* 		by name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Creates the structure storing name and age
struct node
{
	char name[32];
	int age;
	struct node *next;
}node;

//Prototypes
void listAddnode(struct node **start, char *name, int age);
void listRemove(struct node **start, char *name);
void listBubbleSort(struct node *list);
void listSwapPos(struct node *listA, struct node *listB);
void listPrint(struct node *list);

//Main
int main(int argc, char *argv[]) {
	
	//Creates the structure
	struct node *head = NULL;
	
	//Asks the user for 5 different pet names and ages while adding them to the list
	for(int x = 0; x<5; x++) {
		char name[32];
		int age;
		
		printf("Please enter the name for pet #%d\n", x);
		scanf(" %s", name);
		puts("\tPlease enter their age");
		scanf(" %d", &age);
		
		//Makes everything the user just typed lowercase
		for(int y=0; y<sizeof(name); y++){
			name[y] = tolower(name[y]);
		}
		
		//Adds the information to the list
		listAddnode(&head, name, age);
	}
	
	//prints out exsactly what is in the list
	puts("\n\nNon-Alphabetized Order:");
	listPrint(head);
	puts("\n");
	
	//Alphabetizes the list and prints it out
	puts("Alphabetized Order:");
	listBubbleSort(head);
	listPrint(head);
	
	//asks the user for 2 names to remove from the list
	for(int x=0; x<2; x++){
		char name[32];
		puts("\nType the name of the pet you want to remove");
		scanf(" %s", name);
		
		//because everything in the list is stored in lower case, this is made lower case too
		for(int y=0; y<sizeof(name); y++){
			name[y] = tolower(name[y]);
		}
		
		//tries to remove the item from the list
		listRemove(&head, name);
	}
	
	//prints out the new list with the removed items
	puts("\nNew Alphabetized Order:");
	listBubbleSort(head);
	listPrint(head);
	
	return 0;
}

void listAddnode(struct node **start, char *name, int age) {
	
	//Creates space in memory with temp pointer
	struct node *newAdd = ( struct node*)malloc(sizeof(struct node));
	
	//adds information to space in memory
	strcpy(newAdd->name, name);
	newAdd->age = age;
	
	//sets the next node to the first node in the list, then replaces the first node with the new node
	newAdd->next = *start;
	*start = newAdd;
}

void listRemove(struct node **start, char *name) {
	
	//creates temp structures
	struct node *current = *start;
	struct node *previous = NULL;
	
	
	//checks to see if the first node is the one we are looking for
	if(current != NULL && (strcmp(current->name, name)) == 0 ) {
		
		//unlinks the first node and sets the head 1 node further
		*start = current->next;
		
		//frees the space in memory the node was taking up 
		free(current);
		return;
	}
	
	//moves the current node forward as long as the node is NOT the one we are looking for
	while(current != NULL && (strcmp(current->name, name)) != 0 ) {
		previous = current;
		current = current->next;
	}
	
	//If we reach the end of the list, and didn't find the node, then it is not in the list
	if(current == NULL){
		printf("%s is not in the Linked List\n", name);
		return;
	}
	
	//unlinks the current node
	previous->next = current->next;
	//frees the memory of the current node
	free(current);
}

//sorts the list Alphabeticly 
void listBubbleSort(struct node *list) {
	
	//State varible
    int swapped;
    
    //temp pointers
    struct node *ptr1;
    struct node *lptr = NULL;
  
  	//If list is empty
    if (list == NULL) {
    	return;
	}
	
	//Embedded while loop that runs a bubble sort algorithm
    do
    {
        swapped = 0;
        ptr1 = list;
  		
        while (ptr1->next != lptr)
        {
        	//Checks to see if the names match up
            if ( (strcmp( ptr1->name, ptr1->next->name )) > 0 )
            { 
                swapped = 1;
                listSwapPos(ptr1, ptr1->next);
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

//Swaps the data in the structures
void listSwapPos(struct node *listA, struct node *listB) {
	
	//temp vars to hold the data from listA
    int ageTemp = listA->age;
    char nameTemp[32];
	strcpy(nameTemp, listA->name);
	
	//sets ListA to listB
    listA->age = listB->age;
	strcpy(listA->name, listB->name);
    
    //Uses temp data to set listB to what listA was
    listB->age = ageTemp;
    strcpy(listB->name, nameTemp);
}

//Goes through the list and prints out each structure
void listPrint(struct node *list) {
	
	struct node *current = list;
	
	while(current != NULL){
		//Because everything is storeed lower case, makes the first letter uppercase
		printf("the pet named: %c%s is %d years old\n", toupper(current->name[0]), &current->name[1], current->age);
		current = current->next;
	}
}
