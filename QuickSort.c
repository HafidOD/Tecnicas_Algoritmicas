/* C implementation QuickSort */
#include<stdio.h> 

void printArray(int arr[], int size);
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

void printPositions(int i, int j, int n, int h){
	if (j<0){
		j=0;
	}
	if (i>=n){
		i=n-1;
	}
	if (h>=n){
		h=n-1;
	}
	for(int k=0; k < n; k++){
		if(k==i || k==j || k==h){
			if (k==i) {
				printf("i\t");
			}
			if (k==j){
				printf("j\t");
			} 
			if (k==h){
				printf("Piv\t");
			}
		} else {
			printf("\t");
		}
	}
	printf("\n");
}


/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		printf("valor de piv: %d\n\n", arr[high]);
		printPositions(i, j, 7, high);
		printArray(arr, 7);
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
			printPositions(i, j, 7, high);
			printArray(arr, 7);
			
		} 
	} 

	swap(&arr[i + 1], &arr[high]); 
	
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d\t", arr[i]); 
	printf("\n\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
	int arr[] = {10, 80, 30, 90, 40, 50, 70}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	quickSort(arr, 0, n-1); 
	printf("Sorted array: "); 
	printArray(arr, n); 
	return 0; 
} 
