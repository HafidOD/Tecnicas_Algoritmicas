#include <stdio.h>

void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
void printJArray(int arr[],int size,int j);
void printNo(int size,int j);
void printPipes(int j);
void printSi(int size,int j);

int main() {
	
	int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	printf("Arrey Original:\n");
	printArray(arr, n);

	bubbleSort(arr, n); 
	
	printf("\n\nArrey Ordenado:\n"); 
	printArray(arr, n); 
	
	printf("\n\nFin del programa");
	getchar();

	return 0; 
}
void swap(int *xp, int *yp){ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(int arr[], int n){ 
	int i, j; 
	for (i = 0; i < n-1; i++){ 
		printf("\n\n");
		for(int k=0;k<=n;k++){
			printf("\t");
		}
		printf("Iteracion de i = %d\n",i);
		// Last i elements are already in place    
		for (j = 0; j < n-i-1; j++){
			printJArray(arr,n-i,j);
			printPipes(j);
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				printSi(n,j);
				printf("\n");
			} else {
				printNo(n,j);
			}
		}
	}
} 

void printPipes(int j){
	for(int i=0;i<j;i++){
		printf("\t");
	}
	printf("|_______|");
}

void printArray(int arr[], int size){ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d\t", arr[i]); 
	printf("\n"); 
} 

void printJArray(int arr[],int size,int j){
	printf("j=%d\t",j);
	for(int i=0;i<size;i++){
		printf("%d\t", arr[i]); 
	}
	printf("\n\t"); 
	
}

void printNo(int size,int j){
	for(int i=0;i<(size-1)-j;i++){
		printf("\t");
	}
	printf("No cambia valores\n");
}

void printSi(int size,int j){
	for(int i=0;i<(size-1)-j;i++){
		printf("\t");
	}
	printf("Ajustado");
}