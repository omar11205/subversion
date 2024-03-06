#include <stdio.h>

void insertElement(int A[], int *N, int elem, int pos){ //array to be modified, pointer to the size of the array, element to be inserted, position of the array to be inserted
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
	printf("Sizeof after insert: %d\n", n);
	printf("Original array shape:\n");
	for(i = 0; i<n; i++){
		printf("element (%d) = %d\n", i+1, a[i]);
	}
	insertElement(a, &n, 4, 5);
	printf("Before insert an element:\n");
	printf("Size before insert: %d\n", n);
	
	int m = sizeof(a)/sizeof(int);
	printf("Sizeof before insert: %d\n", m);
	
	for(int i = 0; i<n; i++){
		printf("element (%d) = %d\n", i, a[i]);
	}
	return 0;
}

