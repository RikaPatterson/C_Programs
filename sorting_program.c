//Rika Patterson
//Sorting Program
//Created May 8th, 2025

//Import Necessary Library Functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //For Random Number Generation
#include <unistd.h> //For "sleep(1);"
#include <stdbool.h> //For boolean variables.

//BubbleSort Method
void BubbleSort(int array[], int length, int temp)
{
	//Variables
	bool arraySorted = true; //Used to exit the sorting algorithm.
	
	//Print the unsorted array.
	printf("\n\tUnsorted:\t");
	//Run through every position in the array.
	for(int i=0; i<length; i++)
	{
		//Add an extra leading space character when displaying a single-digit number. This keeps the columns even.
		if(array[i]<10)
		{
			printf(" ");
		}

		//Display the number.
		printf("%d", array[i]);

		//Add a comma and space character if this isn't the last digit in the array.
		if(i<(length-1))
		{
			printf(", ");
		}
	}
	
	//Bubble Sort Algorithm
	//Run through every position in the array.
	for(int i=0; i<(length-1); i++)
	{
		//Is the array sorted now? We'll set algorithm-exiting variable to "true" and then raise a flag if the array is found to not be sorted.
		arraySorted = true;
		
		//Run through every position in the array.
		for(int i=0; i<(length-1); i++)
		{
			//If the value in the current position is greater than the value proceding it...
			if(array[i]>array[i+1])
			{
				//...flag the array as not currently sorted.
				arraySorted = false;
			}
		}

		//If the array is sorted...
		if(arraySorted==true)
		{
			//...state so...
			printf(" (Sorted!)\n");
			//...and exit the sorting algorithm.
			break;
		}

		//On the next line we will be displaying a graphic to depict which numbers have been moved towards the beginning of the list.
		//Start with blank space where the row label would be.
		printf("\n\t         \t     ");

		//Run through every position in the array.
		for(int i=0; i<(length-1); i++)
		{
			//If the value in the current position is greater than the value in the position after it...
			if(array[i]>array[i+1])
			{
				//...store the value of the current position.
				temp = array[i];

				//Set the value of the current position to the value of the position after it.
				array[i] = array[i+1];

				//Set the value of the next position to the stored value from the current position.
				array[i+1] = temp;

				//Place an arrow graphic under the number which is currently being moved towards the beginning of the list.
				printf("↵   ");
			}
			//Otherwise...
			else
			{
				//...insert space characters under the digits that did not move towards the beginning of the list during this pass.
				printf("    ");
			}
		}
		
		//Print this round of sorting.
		printf("\n\tPass %d Result:\t", i+1);
		//Run through every position in the array.
		for(int i=0; i<length; i++)
		{
			//Add an extra leading space character when displaying a single-digit number. This keeps the columns even.
			if(array[i]<10)
			{
				printf(" ");
			}

			//Display the number.
			printf("%d", array[i]);

			//Add a comma and space character if this isn't the last digit in the array.
			if(i<(length-1))
			{
				printf(", ");
			}
		}
	}
}

//SelectionSort Method
void SelectionSort(int array[], int length, int temp)
{
	//Variables
	int min = 0; //Used to store the location of the smallest found value within the array.
	
	//Print the unsorted array.
	printf("\n\tUnsorted:\t");
	//Run through every position in the array.
	for(int i=0; i<length; i++)
	{
		//Add an extra leading space character when displaying a single-digit number. This keeps the columns even.
		if(array[i]<10)
		{
			printf(" ");
		}

		//Display the number.
		printf("%d", array[i]);

		//Add a comma and space character if this isn't the last digit in the array.
		if(i<(length-1))
		{
			printf(", ");
		}
	}

	//Place an arrow graphic under the number which is currently being sorted. This graphic begins under the first number in the array and will be labeled during the following for-loop.
	printf("\n\t         \t ⮤");
	
	//Selection Sort Algorithm
	//Run through every position in the array.
	for(int i=0; i<(length-1); i++)
	{
		//Until proven otherwise, we will assume that the current position holds the smallest value within the remainder of the array.
		min = i;

		//Run through every position in the array, starting from the array position after the current one.
		for(int b=(i+1); b<length; b++)
		{
			//If a value is found that is lesser than the value in the current position...
			if(array[b]<array[min])
			{
				//...save the location of that newfound minimum value.
				min = b;
			}
		}

		//If a smaller value was discovered further down in the array...
		if(min!=i)
		{
			//...store the value of the current position.
			temp = array[i];

			//Set the value of the current position to the value of minimum discovered value.
			array[i] = array[min];

			//Set the value of the position which contains the minimum discovered value to the value which was previously stored in the current position.
			array[min] = temp;
			
			//Display the minimum discovered value underneath the current position to convey which numbers are being swapped.
			printf(" %d", array[i]);
		}
		//If a smaller value was NOT discovered during this pass...
		else
		{
			//...the arrow graphic underneath the current position will state so.
			printf(" No Swap");
		}
		
		//Print this round of sorting.
		printf("\n\tPass %d Result:\t", i+1);

		//Run through every position in the array.
		for(int i=0; i<length; i++)
		{
			//Add an extra leading space character when displaying a single-digit number. This keeps the columns even.
			if(array[i]<10)
			{
				printf(" ");
			}

			//Display the number.
			printf("%d", array[i]);

			//Add a comma and space character if this isn't the last digit in the array.
			if(i<(length-1))
			{
				printf(", ");
			}
		}

		//If we have reached the final digit in the array...
		if(i==(length-2))
		{
			//...then the array is sorted.
			printf(" (Sorted!)");
		}
		//Otherwise...
		else
		{
			//...on the next line we will be displaying a graphic to depict which numbers have been swapped.
			//Start with blank space where the row label would be.
			printf("\n\t         \t     ");

			//Depending how far into the array we currently are (i) we will insert space characters under the digits that have already been sorted.
			for(int j=0; j<i; j++)
			{
				printf("    ");
			}

			//Place an arrow graphic under the number which is currently being sorted. This graphic will be labeled during the next iteration of this for-loop.
			printf("⮤");
		}

	}

}

//InsertionSort method
void InsertionSort(int array[], int length, int temp)
{
	//Print the unsorted array.
	printf("\n\tUnsorted:\t");
	//Run through every position in the array.
	for(int i=0; i<length; i++)
	{
		//Add an extra leading space character when displaying a single-digit number. This keeps the columns even.
		if(array[i]<10)
		{
			printf(" ");
		}

		//Display the number.
		printf("%d", array[i]);

		//Add a comma and space character if this isn't the last digit in the array.
		if(i<(length-1))
		{
			printf(", ");
		}
	}
	
	//Insertion Sort Algorithm
	//Run through every position in the array.
	for(int i=1; i<=(length-1); i++)
	{
		//"p" represents the current position in the array that is being sorted.
		int p = i;

		//Start from the current position in the array for this pass, working backwards until reaching the beginning of the array.
		//Comparing "array[p] < array[p-1]", if the value current position in the array is less than the value in the position behind it...
		while(p > 0 && array[p] < array[p-1])
		{
			//...copy the value in the current position.
			temp = array[p];

			//Set the value in the current position to the value preceeding it in the array.
			array[p] = array[p-1];

			//Set the value of the previous position in the array to the copied value.
			array[p-1] = temp;

			//Iterate down.
			p--;
		}
		
		//Print this round of sorting.
		printf("\n\tPass %d Result:\t", i+1);
		//Run through every position in the array.
		for(int i=0; i<length; i++)
		{
			//Add an extra leading space character when displaying a single-digit number. This keeps the columns even.
			if(array[i]<10)
			{
				printf(" ");
			}

			//Display the number.
			printf("%d", array[i]);

			//Add a comma and space character if this isn't the last digit in the array.
			if(i<(length-1))
			{
				printf(", ");
			}
		}
	}

	//The array is sorted.
	printf(" (Sorted!)\n");
}

//Main Method
int main()
{
	//Variables
	int length = 0; //Array Length
	int number = 0; //Stored Number Values
	int array[100]; //Points To Array Locations
	int array2[100]; //Duplicate Array for SelectionSort Method (Arrays cannot be passed by value in C.)
	int array3[100]; //Duplicate Array for InsertionSort Method (Arrays cannot be passed by value in C.)
	int temp; //Used to store values as we sort.
	int clearStandardInput; //Used to clear stdin in the case of bad data entry by the user.
	
	//Generate Random Number Seed
	srand(time(NULL));
	
	//Welcome Prompt
	printf("\n________________________________________________________________________");
	printf("\nRika Patterson\nSorting Program\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("\nThis program generates a random list of numbers and then sorts\nthem using a \"bubble sort\" algorithm and a \"selection sort\" algorithm.\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

	//We will keep prompting the user to enter a value utill they enter a number between 2 and 99.
	while(1==1)
	{
		//Ask for a value.
		printf("How many numbers would you like to sort?: ");

		//Read the data input by the user ("scanf" will read the input and immediately check to see if it's a whole number).
		//If the user entered an erroneous value (anything other than an integer between 2 and 99)...
		if(scanf("%d", &length)!= 1 || length<=1 || length>99)
		{
			//...clear stdin. (This clears out the input and allows for a fresh new value to be entered.)
			do
			{
				clearStandardInput = getchar();
			} while(clearStandardInput!='\n');
			
			//Provide a friendly error message.
			printf("                                          Please enter a number between 2 and 99.\n\n");
			
		}
		//Otherwise...
		else
		{
			//...exit the "while" loop and proceed with the rest of the program.
			break;
		}
	}

	//Generate Random Numbers
	for(int i=0; i<length; i++) //Run through every position in the array.
	{
		number = rand() % 100; //Generate a number between 0 and 99.
		
		//Assign the current location in the array to this number.
		array[i] = number;
		array2[i] = number;
		array3[i] = number;
	}
	
	//Print the unsorted array.
	printf("\nUnsorted list of numbers: ");
	for(int i=0; i<length; i++)
	{
		printf("%d", array[i]);
		if(i<(length-1))
		{
			printf(", ");
		}
	}

	printf("\n________________________________________________________________________");

	//Wait one second after displaying the randomly generated list of numbers.
	//(I think it looks nicer to pause between displaying these two sections to more clearly differentiate what is occuring.)
	sleep(1);
	
	//Call BubbleSort Method
	printf("\n\n\"Bubble Sort\" Algorithm");
	BubbleSort(array, length, temp);
	
	//Call SelectionSort Method
	printf("\n\n\"Selection Sort\" Algorithm");
	SelectionSort(array2, length, temp);
	
	//Call InsertionSort Method
	printf("\n\n\"Selection Sort\" Algorithm");
	InsertionSort(array3, length, temp);

	printf("\n________________________________________________________________________\n\n\n");
	
	//Terminate Program
	return 0;
}