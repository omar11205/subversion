#include <stdio.h>
#include <stdlib.h>

void PrintHelloWorld(){
	printf("Hello world\n");
}

int *Add(int* a, int* b){ 
	//si lo que quiero es una función que me devuelva
	//un pointer el tipo de retorno debe ser int*
	//para corregir el error se usa asignación dinámica de memoria
	int* c = (int*)malloc(sizeof(int));
	//el contenido del pointer va a estar en heap
	//para modificar el contenido "*c = ..."
	*c = (*a)+(*b);
	return c;

}

int main() {
	int a = 2, b = 4;
	//si add devuelve un pointer se lo debe recoger
	//en una variable pointer
	int* ptr = Add(&a,&b);
	PrintHelloWorld();
	printf("Sum = %d\n", *ptr);
	free(ptr);
	return 0;
}

