#include <stdio.h>

void insertar(int A[], int *N, int elem, int pos){ //array to be modified, pointer to the size of the array, element to be inserted, position of the array to be inserted
	int i;
	for(i=*N-1; i>=pos; i--){
		A[i+1] = A[i];
	}
	A[pos] = elem;
	*N = *N + 1;
}
	

int main(void) {
	int i = 0;
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);
	printf("original size array: %d\n", n);
	printf("original array shape:\n");
	for(i = 0; i<n; i++){
		printf("element (%d) = %d\n", i+1, a[i]);
	}
	insertar(a, &n, 4, 5);
	printf("Before insert an element:\n");
	printf("size befor insert: %d\n", n);
	//int l = sizeof(a)/sizeof(int);
	
	for(int i = 0; i<n; i++){
		printf("element (%d) = %d\n", i, a[i]);
	}
	return 0;
}

