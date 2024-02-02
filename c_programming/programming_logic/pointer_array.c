#include <stdio.h>

int main(void) {
	int A[] = {2,4,5,8,1};
	int i;
	//para imprimir la dirección del primer elemento
	printf("Direccion del primer elemento del array A: %d\n", A);
	printf("Direccion del primer elemento del array A: %d\n", &A[0]);
	//para imprimir el valor del primer elemento
	printf("Valor del primer elemento del array A: %d\n", *A);
	printf("Valor del primer elemento del array A: %d\n", A[0]);
	
	//para imprimir la dirección y el valor de cualquier elemento
	for (i=0;i<5;i++){
		//pointer notation
		printf("Address (p notation) = %d\n", A+i);
		printf("Value (p notation) = %d\n", *(A+i));
	}
	
	for (i=0;i<5;i++){
		//index notation
		printf("Address (i notation) = %d\n", &A[i]);
		printf("Value (i notation) = %d\n", A[i]);
	}
	
	return 0;
}

