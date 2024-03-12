#include <stdio.h>

char *changeValue(char *parameter){ 
	parameter = "Adios";
	return parameter;
}

int main(void) {
	char *arg = "Hola";
	printf("Antes de llamar la función: %s\n", arg);
	arg = changeValue(arg);
	printf("Despues de llamar la funcion: %s\n", arg);
	return 0;
}

