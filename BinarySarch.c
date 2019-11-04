#include <stdio.h> 
void printArray(int arr[], int n) ;

int binarySearch(int arr[], int l, int r, int x) 
{ 
    
	if (r >= l) { 
		int mid = l + (r - l) / 2; 
		//printf("La mitad es: %d\n", mid);

		if (arr[mid] == x) 
			return mid; 

		if (arr[mid] > x) 
			return binarySearch(arr, l, mid - 1, x); 

		return binarySearch(arr, mid + 1, r, x); 
	} 

	return -1; 
} 

int main(void) 
{ 
	int arr[] = { 2, 6, 10, 15, 23, 40, 43, 55 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("Array Original:\n");
	printArray(arr, n);
	int x = 55; 
	int result = binarySearch(arr, 0, n - 1, x); 
	if (result == -1)
	    printf("\nEl numero %d no esta presente en el array\n", x); 
	
	else
	    printf("\nEl numero %d esta en el indice %d", x, result); 
	return 0; 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d\t", arr[i]); 
	printf("\n\n"); 
	// 140300042
} 
