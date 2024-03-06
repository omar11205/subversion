#include <stdio.h>

void eliminateElement(int A[], int *N, int pos){ //array to be modified, pointer to the size of the array, element to be eliminated, position of the array element to be eliminated
	int i;
	for(i=pos; i<*N-1; i++){
		A[i] = A[i+1];
	}
	*N = *N - 1;
}
	

int main(void) {
	int i = 0;
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);
	printf("original size array: %d\n", n);
	for(i = 0; i<n; i++){
		printf("element (%d) = %d\n", i+1, a[i]);
	}
	eliminateElement(a, &n, 0);

	printf("array before elimination. Size; %d\n", n);
	for(int i = 0; i<n; i++){
		printf("element (%d) = %d\n", i+1, a[i]);
	}
	int m = sizeof(a)/sizeof(int);
	printf("size with sizeof: %d\n", m);
	return 0;
}

