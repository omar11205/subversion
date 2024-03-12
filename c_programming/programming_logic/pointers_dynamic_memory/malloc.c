#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *p;
	//malloc devuelve un void pointer (void*) pero p es un pointer
	//a un entero por tanto se coloca (int*) para pasar
	//de void* a int* si hay memoria insuficiente malloc devuelve NULL
	p = (int*)malloc(sizeof(int));
	//esto practicamente significa que se crea un espacio de memoria en heap
	//y la dirección a la que va a apuntar el pointer p ahora va a ser la dirección de memoria
	//que acabo de crear en malloc
	if (p == NULL){
		printf("Memory not allocated");
		exit(0);
	} else {
		printf("Memory successfully allocated by malloc.\n");
		*p = 10;
		printf("Content of the new memory block: %d", *p);
	}

	
	return 0;
}

