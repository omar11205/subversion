#include <stdio.h>

void Clasiffy(char *(A[]), int coun){
	printf("Content of the character array\n");
	for(int i = 0;i<coun;i++){
		printf("String[%d]: %s\n", i, A[i]);
	}
}

int main(void) {
	char *concept[] = {
		"HEN",
		"HED",
		"HOD"
	};
	Clasiffy(concept, 3);
	return 0;
}

