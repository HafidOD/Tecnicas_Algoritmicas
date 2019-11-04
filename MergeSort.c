#include<stdlib.h> 
#include<stdio.h> 

typedef struct Nodo{
    int array[10];
    int elem;
    struct Nodo *next;
    struct Nodo *prev;
}Nodo;

void merge(int arr[], int l, int m, int r, int Nodo);
void mergeSort(int arr[], int l, int r, Nodo **apnd);
Nodo *crea_nodo(Nodo **tail);
int inserta_lista(Nodo *H, int arr[], int l , int r);
void libera_memoria(Nodo *H);
void imprime_nodo(int A[], int inicio, int size);
void imprimir_G(Nodo *H, int size);

int main(){ 
    int arr[] = {38, 27, 43, 3, 9, 82, 10};  
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
    Nodo *H = 0;
    Nodo *T = 0;
    
    H=crea_nodo(&T);
    
    printf("\nArreglo Inicial:\t");
    imprime_nodo(arr, 0,arr_size-1); 
    mergeSort(arr, 0, arr_size - 1, H); 
    imprimir_G(H, arr_size-1);
    
    libera_memoria(H);
    printf("\nArreglo Final: \t");
    imprime_nodo(arr, 0, arr_size-1);
    return 0; 
}

void merge(int arr[], int l, int m, int r, int Nodo){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;
    
    // Arreglos temporales
    int L[n1], R[n2];
    
    // Copia la informacion en los arreglos temporales
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    
    // Merge
    i = 0; 
    j = 0;  
    k = l; 
    while (i < n1 && j < n2){ 
        if (L[i] <= R[j]){ 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }
    
    // Copia los elementos sobrantes si es que hay alguno
    while (i < n1){ 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    
    // Copia los elementos sobrantes si es que hay alguno
    while (j < n2){ 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
    inserta_lista(Nodo, arr, l, r);
}

void mergeSort(int arr[], int l, int r, Nodo **apnd){ 
    if (l < r){
        
        int m = l+(r-l)/2;
        inserta_lista(apnd, arr, l, r);
        mergeSort(arr, l, m, apnd);
        mergeSort(arr, m+1, r, apnd);
        merge(arr, l, m, r, apnd); 
        
    } else{
        
        inserta_lista(apnd, arr, l, r);
    }
}

Nodo *crea_nodo(Nodo **tail){
    
 Nodo *H = 0; 
 Nodo *T = 0;
 
    if((H = malloc(sizeof(Nodo)))== 0){
        
        return 0;
    }
    if((T = malloc(sizeof(Nodo)))== 0){
        
       free(H);
       return 0;
    }
    H->elem = 0;
    H->next = T;
    H->prev = H;
    T->next = T;
    T->prev = H;
    *tail = T;
    return H;
}

int inserta_lista(Nodo *H, int arr[], int l , int r){
    
	Nodo *apnodo;
	Nodo *newitem = 0;
	int i, con = 0;

    if(H==0){
        
		return 0;
	}
	
	if((newitem=(malloc(sizeof(Nodo))))==0){
	    
		return 0;
	}
	
	for(i = l; i <= r; i++){
	    
	    newitem->array[con] = arr[i];
	    con++;
	}
	apnodo = H;
	
	while(apnodo->next!=apnodo->next->next ){
	    
		apnodo = apnodo->next;
	}
	newitem->elem = apnodo->elem+1;
	newitem->prev = apnodo;
	newitem->next = apnodo->next;
	apnodo->next = newitem;
	newitem->next->prev = newitem;
	return 1;
}

void libera_memoria(Nodo *H){
    
    Nodo *apnodo = H->next;
    
    while (apnodo != apnodo->next){
        
        apnodo->prev->next = apnodo->next;
        apnodo->next->prev = apnodo->prev;
        free(apnodo); 
        apnodo = H->next;
    }
    free(H);
    free(apnodo);
}

void imprime_nodo(int A[], int inicio, int size){ 
    
    int i=0; 
        while(A[i] !=0 && i <= size){ 
            
            printf("%d\t", A[i]);
            i++;
        }
    printf("\n\n"); 
}

void imprimir_G(Nodo *H, int size){
    Nodo *apnodo = H->next;
    int con = 0;
    
    while (apnodo != apnodo->next){
        printf("Step %d: \t", apnodo->elem);
        imprime_nodo(apnodo->array,0,size);
        apnodo=apnodo->next;
    }
}
