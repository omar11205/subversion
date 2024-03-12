#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *p; //holds the direction of the memory allocated
	int n; //holds the number or elements of the pointer
	int *r; //realocates memory from another pointer
	
	printf("Enter the number of elements of the array\n");
	scanf("%d", &n);
	printf("Selected array elements: %d\n", n);
	p = (int*)malloc(n*sizeof(int));
	//if i need an array of n integers the memory for that array is n sizes of the memory cost of int
	
	if (p == NULL){
		printf("Memory not allocated");
		exit(0);
	} else {
		printf("Memory successfully allocated by malloc.\n");
		//filling the array elements with for using *(p + i) = p[i]
		for (int i = 0; i<n; i++){
			p[i] = 2*i + 1;
		}
		//printing the array elements
		printf("The elements of the array are: \n");
		for (int i = 0; i<n; i++){
			printf("Element %d: %d\n", i, p[i]);
		}
		//resizing memory factor
		int rmf = 10;
		r = (int*)realloc(p, rmf*sizeof(int));
		
		if (r == NULL){
			printf("Realocation of memory fail");
			exit(0);
		} else {
			printf("Memory successfully re-allocated by realloc.\n");
			printf("The elements of the array are: \n");
			for (int i = 0; i<(rmf); i++){
				printf("Element %d: %d\n", i, p[i]);
			}
		}
	}
	
	free(r);
	p = NULL;
	r = NULL;

	return 0;
}

