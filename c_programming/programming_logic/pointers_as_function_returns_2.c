#include <stdio.h>
#include <stdlib.h>

int Add(int *a, int *b){ //como lo que van a recibir a y b de Add son direcciónes de memoria
	//a y b deben ser pointers ( que es el unico tipo de datos que maneja el tipo de dato de dirección de memoria)
	//para trabajar con los valores a los que apuntan los pointers a y b se debe desreferenciar con (*)
	int c = (*a)+(*b);
	return c;
}

int main() {
	//si quiero llamar a Add con paso por referencia
	//debo pasar la dirección de memoria de a y b después de inicializar las variables
	//en la llamada de Add
	int a = 2, b = 4;
	int c = Add(&a,&b);
	printf("Sum = %d\n", c);
	return 0;
}

