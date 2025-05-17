//Rika Patterson
//Doubly-Linked List Program
//Created May 17th, 2025

//Import Necessary Library Functions
#include<stdio.h>
#include<malloc.h>

//Structure that houses the nodes.
typedef struct nodeData
{
    struct nodeData *prev; //Points to the address of the previous node.
    int data;              //Houses numerical data stored within nodes.
    struct nodeData *next; //Points to the address of the next node.
}Node, *prev, *next;

Node node, *temp;
void makeList(Node *);
void showList(Node *);

//makeList Method - Makes the initial node list.
void makeList(Node *head)
{
	node.next = NULL;
	node.prev = NULL;
	head = &node;
	fflush(stdin);
	
	int numNodes = 0;
	
	//This is where the user will enter in the number of nodes that they would like in their linked list.
	printf("How many nodes would you like in your doubly-linked list?: ");
	scanf("%d", &numNodes);
	printf("\n");

	//This array is where the user will insert values into the nodes as they are created.
	for(int i=0; i<numNodes; i++)
	{
		head->next = (Node *)malloc(sizeof(Node));
		head->next->prev = (head);
		head = (head->next);
		if(i==0)
		{
			head->prev = NULL;
		}
		printf("Enter a numerical value to be stored in node #%d: ", i+1);
		scanf("%d", &head->data);
	}
}

//showList Method - Displays the list to the user.
void showList(Node *head)
{
	//Variables
    int i = 1;
	
	head = node.next;
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	while(head)
	{
		printf("\nNode #%d", i);
		printf("\n\tNode Address:");
		printf("\t\t\t0x%x", head);
		printf("\n\tValue Stored:");
		printf("\t\t\t%d", head->data);
		printf("\n\tAddress of Previous Node:");
		printf("\t0x%x", head->prev);
		printf("\n\tAddress of Next Node:");
		printf("\t\t0x%x\n", head->next);
		head = (head->next);
		i++;
		if(head)
		{
			getchar();
		}
	}
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
	getchar();
}

//Main Method
int main()
{
    //Create the initial node.
	Node *head = (Node *)malloc(sizeof(Node));
	
	//Print the header.
	printf("______________________________________________________________________________________");
	printf("\n\nRika Patterson\nDoubly-Linked List Program\n\n");
	printf("This program will allow you to create a doubly-linked list of integers.\nOnce you have created your list with the values you like you may\nalter it by adding or deleting individual nodes.");
	printf("\n(Press 'Enter' to continue.) ");
	getchar();
	printf("\n\n\n");
	
	//The user makes the doubly-linked list.
	makeList(head);
	
	//The program prints the list to the user.
	showList(head);
}