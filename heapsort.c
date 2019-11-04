// C++ program for implementation of Heap Sort 
#include <stdio.h> 
void swap(int *xp, int *yp);
void printPositions(int i, int l, int r, int n);
void printArray(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

// Driver program 
int main() 
{ 
	int arr[] = {12, 11, 13, 50, 60, 70, 55, 40, 30, 20, 10}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	printf("Array Original:\n");
	printArray(arr, n);
	
	heapSort(arr, n); 
	
	printf("Array ordenado:\n");
	printArray(arr, n); 
} 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2*i + 1; // left = 2*i + 1 
	int r = 2*i + 2; // right = 2*i + 2 
	
	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 
	printPositions(i,l,r,n); // 140300042
	printArray(arr,n); // 140300042
	
	
	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 
	
	// If largest is not root 
	if (largest != i) 
	{ 
		swap(&arr[i], &arr[largest]); 
		
		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
	// Build heap (rearrange array) 
	printf("______________________________________________________________________________________\n");
	printf("Primera Fase\n\n");
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i); 
	
	// One by one extract an element from heap
	printf("______________________________________________________________________________________\n");
	printf("Segunda Fase\n\n");
	for (int i=n-1; i>=0; i--) 
	{ 
		// Move current root to end 
		swap(&arr[0], &arr[i]); 
		
		// call max heapify on the reduced heap 
		heapify(arr, i, 0); 
	} 
} 

/* function to print positions of i, l, r */
void printPositions(int i, int l, int r, int n)
{
	for(int k=0; k < n; k++){
		if(k==i || k==l || k==r){
			if (k==i) {
				printf("i\t");
			} if (k==l) {
				printf("l\t");
			} if (k==r) {
				printf("r\t");
			}
		} else {
			printf("\t");
		}
	}
	printf("\n");
	// 140300042
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

void swap(int *xp, int *yp)
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
	/* 140300042 */
} 
