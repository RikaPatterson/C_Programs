//Rika Patterson
//Sorting Program
//Created May 8th, 2025

//Import Necessary Library Functions
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //For Random Number Generation
#include <unistd.h> //For "sleep(1);"

//BubbleSort Method
void BubbleSort(int array[], int length, int temp)
{
	//Variables
	int swapOccured = 0; //Used to exit the sorting algorithm.
	
	//Print the unsorted array.
	printf("\n\tUnsorted:\t");
	for(int i=0; i<length; i++)
	{
		printf("%d", array[i]);
		if(i<(length-1))
		{
			printf(", ");
		}
	}
	
	//Bubble Sort Algorithm
	//Run through every position in the array.
	for(int i=0; i<(length-1); i++)
	{
		//Run through every position in the array.
		for(int i=0; i<(length-1); i++)
		{
			//If the value in the current position is greater than the value in the position after it...
			if(array[i] > array[i+1])
			{
				//...store the value of the current position.
				temp = array[i];

				//Set the value of the current position to the value of the position after it.
				array[i] = array[i+1];

				//Set the value of the next position to the stored value from the current position.
				array[i+1] = temp;

				//A value swap has occured.
				swapOccured = 1;
			}
		}
		
		//If no values were swapped during this pass then the array is sorted and the sorting algorithm will be exited.
		if(swapOccured == 0)
		{
			break;
		}

		//Reset the exit variable.
		swapOccured = 0;
		
		//Print this round of sorting.
		printf("\n\tPass %d Result:\t", i+1);
		for(int i=0; i<length; i++)
		{
			printf("%d", array[i]);
			if(i<(length-1))
			{
				printf(", ");
			}
		}
	}

	//The array is sorted.
	printf(" (Sorted!)\n");
	
}
//End BubbleSort Method

//SelectionSort method
void SelectionSort(int array[], int length, int temp)
{
	//Variables
	int min = 0; //Used to store the location of the smallest found value within the array.
	
	//Print the unsorted array.
	printf("\n\tUnsorted:\t");
	for(int i=0; i<length; i++)
	{
		printf("%d", array[i]);
		if(i<(length-1))
		{
			printf(", ");
		}
	}
	
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
			if(array[b] < array[min])
			{
				//...save the location of that newfound minimum value.
				min = b;
			}
		}

		//If a smaller value was discovered further down in the array...
		if(min != i)
		{
			//...store the value of the current position.
			temp = array[i];

			//Set the value of the current position to the value of minimum discovered value.
			array[i] = array[min];

			//Set the value of the position which contains the minimum discovered value to the value which was previously stored in the current position.
			array[min] = temp;
		}
		
		//Print this round of sorting.
		printf("\n\tPass %d Result:\t", i+1);
		for(int i=0; i<length; i++)
		{
			printf("%d", array[i]);
			if(i<(length-1))
			{
				printf(", ");
			}
		}
	}

	//The array is sorted.
	printf(" (Sorted!)\n");
}
//End SelectionSort method

//Main Method
int main()
{
	//Variables
	int length = 0; //Array Length
	int number = 0; //Stored Number Values
	int array[100]; //Points To Array Locations
	int arraya[100]; //Duplicate Array for SelectionSort Method (Arrays cannot be passed by value in C.)
	int temp; //Used to store values as we sort.
	
	//Generate Random Number Seed
	srand(time(NULL));
	
	//Welcome Prompt
	printf("\n_____________________________________________________________________");
	printf("\nRika Patterson\nSorting Program\n\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("\nThis program generates a random list of numbers and then sorts\nthem using a \"bubble sort\" algorithm and a \"selection sort\" algorithm.\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\nHow many numbers would you like to sort?: ");
	scanf("%d", &length); //User-Defined Array Length

	//Generate Random Numbers
	for (int i=0; i<length; i++) //Run through every position in the array.
	{
		number = rand() % 100; //Generate a number between 0 and 99.
		
		//Assign the current location in the array to this number.
		array[i] = number;
		arraya[i] = number;
	}
	
	//Print the unsorted array.
	printf("\nUnsorted list of numbers: \n");
	for (int i=0; i<length; i++)
	{
		printf("%d", array[i]);
		if(i<(length-1))
		{
			printf(", ");
		}
	}

	printf("\n_____________________________________________________________________");

	//Wait one second after displaying the randomly generated list of numbers.
	//(I think it looks nicer to pause between displaying these two sections to more clearly differentiate what is occuring.)
	sleep(1);
	
	//Call BubbleSort Method
	printf("\n\nBubbleSort");
	BubbleSort(array, length, temp);
	
	//Call SelectionSort Method
	printf("\n\nSelectionSort");
	SelectionSort(arraya, length, temp);

	printf("\n_____________________________________________________________________\n\n\n");
	
	//Terminate Program
	return 0;
}
//End Main Method
//End Program