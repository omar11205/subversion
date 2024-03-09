#include <stdio.h>

//binary search is a search algorithm optimized for ordered lists.
//to order the list use bubbleSort

//binary search splits in two the array and start verifing from the center to left and right; if the element is big than the most-left element all the left part will be discarted

int binarySearchGPT(int A[], int N, int elem) {
	int start = 0;
	int end = N - 1;
	int mid;
	
	while (start <= end) {
		mid = (start + end) / 2;
		
		// If element is found at mid
		if (A[mid] == elem)
			return mid;
		
		// If element is greater, search in the left half
		else if (elem < A[mid])
			end = mid - 1;
		
		// If element is smaller, search in the right half
		else
			start = mid + 1;
	}
	
	// If element is not present in the array
	return -1;
}

int binarySearch2(int A[], int N, int elem){ //if the element is not present in the array returns -1, the position starts with 0
	int start=0;
	int end=N-1;
	int mid = (start+end)/2;
	
	while(start<=end && elem!=A[mid]){
		if(elem < A[mid])
			end = mid - 1;
		else
			start = mid + 1;
		
		mid = (start + end)/2;
	}
	if(start<=end)
		return mid;
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
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	int n = sizeof(arr)/sizeof(int);
	int result;
	int searchingfor = 6;
	
	bubbleSort(arr, n);
	for(int i = 0; i<n; i++){
		printf("El[%d]: %d\n", i, arr[i]);
	}
	printf("Searching for %d\n", searchingfor);
	result = binarySearch2(arr, n, searchingfor);
	printf("The position of %d in the array is: %d\n", searchingfor, result);
	
	return 0;
}
	
