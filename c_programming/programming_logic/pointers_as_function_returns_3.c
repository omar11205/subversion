#include <stdio.h>
#include <stdlib.h>

//void PrintHelloWorld(){
//	printf("Hello world\n");
//}

int *Add(int* a, int* b){ 
	//si lo que quiero es una funci�n que me devuelva
	//un pointer el tipo de retorno debe ser int* y se
	//debe devolver la direcci�n de c, lo que contiene 
	//un pointer siempre es una direcci�n de memoria
	int c = (*a)+(*b);
	return &c;
	//es muy peligroso devolver direcciones de memoria de funciones:
	//una vez se ejecuta la funci�n, esta se quita del stack y se borra 
	//la variable c por lo tanto *ptr va a contener una direcci�n de memoria de 
	//alguna otra cosa menos lo que yo quiero, porque ya se borr� del stack
}

int main() {
	int a = 2, b = 4;
	//si add devuelve un pointer se lo debe recoger
	//en una variable pointer
	int* ptr = Add(&a,&b);
	printf("Sum = %d\n", *ptr);
	return 0;
}

