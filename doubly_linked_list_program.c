//Rika Patterson
//Doubly-Linked List Program
//Created May 17th, 2025

//Import Necessary Library Functions
#include <stdio.h>
#include <stdlib.h> //For "exit()"
#include <malloc.h> //For "malloc()"
#include <unistd.h> //For "sleep(1);"

//Structure that houses the nodes.
typedef struct nodeData
{
	struct nodeData *prev; //Points to the address of the previous node.
	int data;              //Houses numerical data stored within nodes.
	struct nodeData *next; //Points to the address of the next node.
}Node, *prev, *next; //Defines the variable "Node" of type "struct nodeData", as well as the pointers "*prev", and "*next" which point to other instances of "struct nodeData".

//Variable "aNode" is of our custom type "Node".
Node aNode;

//makeList Method - Makes the initial node list.
void makeList(Node *head)
{
	//Variables
	int numNodes = 0; //User-defined number of nodes.
	aNode.next = NULL; //There is no "next" node, yet.
	aNode.prev = NULL; //There is no "previous" node, yet.

	//Set the "head" pointer to the address of aNode.
	head = &aNode;
	
	//User Input
	printf("How many nodes would you like in your doubly-linked list?: ");
	scanf("%d", &numNodes);
	printf("\n");

	//For every node that the user would like to create...
	for(int i=0; i<numNodes; i++)
	{
		//If this is the first node in the double-linked list...
		if(i==0)
		{
			//...then this node does not point to a previous node.
			head->prev = NULL;
		}

		//The user enters a value to be stored in the "data" variable within the aNode structure.
		printf("Enter a numerical value to be stored in node #%d: ", i+1);
		scanf("%d", &head->data);

		//If this is NOT the last node in the double-linked list...
		if(i<numNodes-1)
		{
			//...set the value of the current node's "next" pointer to the address of a new node.
			head->next = (Node *)malloc(sizeof(aNode));

			//Set the value of the next node's "prev" pointer to the address of the current node.
			head->next->prev = (head);

			//Look at the next node in the list.
			head = (head->next);
		}
	}
}

//showList Method - Displays the list to the user.
void showList(Node *head)
{
	//Variables
	int i = 1; //For while-loop incrementing.
	head = &aNode;
	
	//Wait for one second.
	sleep(1);

	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	while(head)
	{
		//Display Node Information
		printf("\nNode #%d", i);
		printf("\n\tNode Address:");
		printf("\t\t\t0x%x", head);
		printf("\n\tValue Stored:");
		printf("\t\t\t%d", head->data);
		printf("\n\tAddress of Previous Node:");
		printf("\t0x%x", head->prev);
		printf("\n\tAddress of Next Node:");
		printf("\t\t0x%x\n", head->next);

		//Look at the next node in the list.
		head = (head->next);
		
		//Increment
		i++;
	}
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	//Wait for one second.
	sleep(1);
}

//Main Method
int main()
{
    //Variables
	int option = 0; //The user's chosen option.
	Node *head = (Node *)malloc(sizeof(aNode)); //The "head" pointer. It will point to the address of the current node.

	//Welcome Prompt
	printf("\n________________________________________________________________________");
	printf("\n\nRika Patterson\nDoubly-Linked List Program\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("\nThis program will allow you to create a doubly-linked list of integers.\nOnce you have created your list with the values you like you may\nalter it by adding or deleting individual nodes.\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	
	//The user makes the doubly-linked list.
	makeList(head);
	
	//The program prints the list to the user.
	showList(head);
	
	//Options loop.
	printf("Now that you've created your doubly-linked list,\nyou may edit it in the following ways:\n\n");
	while(option != 3)
	{
		//Reset the option variable.
		option = 0;
		
		//Options Prompt
		printf("==========================================================\n");
		printf("\tEnter a '1': Add a new node. (UNDER CONSTRUCTION)\n");
		printf("\tEnter a '2': Delete a node. (UNDER CONSTRUCTION)\n");
		printf("\tEnter a '3': Quit\n");
		printf("==========================================================\n");
		
		//The user enters their option.
		while(option != 1 && option != 2 && option != 3)
		{
			option = 0;
			printf("\nCommand: ");
			scanf("%d", &option);
		}
		
		if(option == 1)
		{
			//Add Node
		}
		
		if(option == 2)
		{
			//Delete Node
		}
	}
	
	//'Quit program' prompt.
	printf("\nThank you, and goodbye.");
	printf("\n______________________________________________________________________________________\n\n");
	
	//Terminate Program
	exit(0);
}