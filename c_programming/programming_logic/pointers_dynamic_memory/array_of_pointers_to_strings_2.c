#include <stdio.h>

void Clasiffy(char *(A[]), int coun) {//ptr version **A
	printf("Content of the character array\n");
	for (int i = 0; i < coun; i++) {
	    printf("Concept[%d]: %s\n", i, A[i]);
	}
	for (int i = 0; i < coun; i++) {
		printf("Memory direction of Concept[%d]: %d\n", i, &(A[i][0]));
	}
	for (int i = 0; i < coun; i++) {
		printf("Memory direction of Pointer[%d]: %d\n", i, &A[i]);
	}
	
}

int main(void) {
	char *(concept[]) = {
		"HENt",
		"HEDt",
		"UODt"
	};
	Clasiffy(concept, 3);
	return 0;
}

