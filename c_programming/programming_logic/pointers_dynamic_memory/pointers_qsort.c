#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b){ //const significa que no puedo alterar la dirección de memoria a la que apunta el pointer
	//int A = (int*)a;  Si hago esto A va a contener la dirección de memoria de a
	//int B = (int*)b;
	//para obtener el contenido de la memoria, desreferenciar el pointer int* con (*)
	int A = *((int*)a);
	int B = *((int*)b);
	return A-B;
	//probar para ordenar de menor a mayor A-B, B-A
	//para ordenar por valor absoluto ABS(A)-ABS(B)
}
int main(){
	int i;
	int A[] = {50, 52, -1, 51, -6, 4};
	qsort(A, 6, sizeof(int), compare);
	for(i = 0; i<6; i++){
		printf("%d " , A[i]);
	}
	return 0;
}

