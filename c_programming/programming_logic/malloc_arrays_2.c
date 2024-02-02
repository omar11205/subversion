#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//first case use
	//size of an array
	int m;
	printf("Enter the size of the array\n");
	scanf("%d", &m);
	int A[m];
	//this will return compilation error: the
	//size of an array cannot be given in
	//run-time 
	printf("%li\n", sizeof(A));
	return 0;
}

