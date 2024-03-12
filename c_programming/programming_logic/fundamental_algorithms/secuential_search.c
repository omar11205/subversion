#include <stdio.h>

//Sequential search is used in disordered lists, for ordered list is highly inefficient

int sequentialSearch(int A[], int N, int elem) {//if the element is not present in the array returns -1, the position starts with 0
	int i = 0;
	while (i < N && elem != A[i]){
		i++;
	}
	
	if (i < N){
		return i; // Element found at position i
	} else {
		return -1; // Element not found
	}
	
}

int main(void) {
	int arr[] = {1};
	int n = sizeof(arr)/sizeof(int);
	int elem = 1;
	int index = sequentialSearch(arr, n, elem);
	printf("n: %d\n", n);
	if (index >= 0){
		printf("The position was: %d\n", index);
	} else {
		printf("The element is'n in the array arr\n"); 
	}
	return 0;
}




