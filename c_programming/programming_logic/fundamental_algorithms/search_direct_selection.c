#include <stdio.h>

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
