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

int main(int argc, char *argv[]) {
	int arr[] = {1,2,3,4,5,6,7,8,9,12,14,45,67,32,13};
	int n = sizeof(arr)/sizeof(int);
	int elem = 12;
	int index = sequentialSearch(arr, n, elem);
	if (index > 0){
		printf("The position was: %d\n", index);
	} else {
		printf("The element is'n in the array arr\n"); 
	}
	return 0;
}




