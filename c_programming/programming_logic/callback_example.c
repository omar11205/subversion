#include <stdio.h>

//Function callback example by sorting an array with BubleSort algorithm
//it will be usefull a pair of flag functions (callback functions)
int increasing(int a, int b){
	if (a>b) {
		return 1;
	} else {
		return -1;
	}
}
	
int decreasing(int a, int b){
	if (a>b) {
		return -1;
	} else {
		return 1;
	}
}

void BubbleSort(int *A, int n, int (*compare)(int, int)){
	int i, j, k, temp;
	for(i = 0; i<n; i++){
		for(j = 0; j<n-1; j++){
			//with ">" sort from lower indices to higher (increasing order)
			//with "<" sort from higher indices to lower (decreasing order)
			if(compare(A[j], A[j+1]) > 0){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
			printf("\nArray Status: ");
			for (k = 0; k<n; k++){
				printf("%d-", A[k]);        
			}
		}
	}
}

int main(void){
	int A[] = {2, 3, 8, 6, 9, 5, 4, 1, 7};
	int n = sizeof(A)/sizeof(int);
	BubbleSort(A, n, decreasing);
	printf("Size of n: %d\n", n);
	return 0;
}

