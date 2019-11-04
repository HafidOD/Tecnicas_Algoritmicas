#include <stdio.h>

void printArray(int arr[], int size);
int buscar(int arr[], int n, int val);

int main()
{
	int val;
	int arr[] = { 2, 10, 15, 4, 8, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf("El array es:  ");
	printArray(arr, n);
	while(true)
	{
		printf("_______________________________________\n");
		printf("\nIngresa el valor a buscar: ");
		scanf("%d", &val);
		//printf("El valor ingresado es %d", val);
		int result = buscar(arr, n, val); 
		(result == -1) ? printf("El numero %d no esta en el array\n", val) 
			: printf("El numero %d esta en el indice: %d\n", 
					 val, result); 
	}
	
	return 0;
}

void printArray(int arr[], int size)
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int buscar(int arr[], int n, int val) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		if (arr[i] == val) 
			return i; 
	return -1; 
} 
