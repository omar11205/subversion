#include <stdio.h>

void cambiarValor (int *parametro){
	*parametro = 20;
}
	void cambiarValorArray (int *parametro){
		for (int i =0;i<(sizeof(parametro)/sizeof(int));i++){
			parametro[i] = i+parametro[i]+5;
		}
	}
int main(void){
	//paso por referencia
	int argumento = 10;
	int arr[7] = {1,2,4,5,6,7,8};
	printf("Antes de llamar la función: %d\n", argumento);
	cambiarValor(&argumento);
	printf("Después llamar función: %d\n", argumento);
}
