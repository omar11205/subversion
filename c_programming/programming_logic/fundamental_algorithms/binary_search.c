#include <stdio.h>

//binary search is a search algorithm optimized for ordered lists.
//to order the list use bubbleSort

//binary search splits in two the array and start verifing from the center to left and right; if the element is big than the most-left element all the left part will be discarted


int busquedaBinaria(int A[], int N, int elem){ //if the element is not present in the array returns -1, the position starts with 0
	int ini=0;
	int fin=N-1;
	int med = (ini+fin)/2;
	
	while(ini<=fin && elem != A[med]){
		if(elem < A[med])
			fin = med - 1;
		else
			ini = med + 1;
		
		med = (ini + fin)/2;
	}
	if(ini<=fin)
		return med;
	else
		return -1;
}

void bubbleSort(int A[], int N){
	int i, j, aux;
	
	for(i=0; i<N-1; i++){
		for(j=i+1; j<N; j++){
			if(A[j] < A[i]){
				aux = A[j];
				A[j] = A[i];
				A[i] = aux;
			}
		}
	}
}
	
	
int main(void) {
	int arr[] = {100,1,5,62,54,847,54,67,20,69,95,12,36,45,65,57};
	int n = sizeof(arr)/sizeof(int);
	bubbleSort(arr, n);
	for(int i = 0; i<n; i++){
		printf("El[%d]: %d\n", (i+1), arr[i]);
	}
	return 0;
}
	
