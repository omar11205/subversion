#include <stdio.h>
#include <stdlib.h>
int Add(int a, int b){
	int c = a+b;
	return c;
	//a, b y c son del scope de Add y ocupan una
	//dirección de memoria diferente a a,b y c 
	//de main
}

int main() {
	int a = 2, b = 4;
	int c = Add(a,b);
	printf("Sum = %d\n", c);
	//el valor de a en main es una copia del a de Add
	//lo mismo para b
	return 0;
}

