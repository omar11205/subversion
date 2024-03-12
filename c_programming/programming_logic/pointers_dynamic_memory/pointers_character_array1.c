#include <stdio.h>
#include <string.h>
//se puede escribir en la zona de argumentos "char* C" ó "char *C" ó "char C[]"
//sin ningún problema pero el compilador prefiere "char* C"
void imprimir1(char* C){
	int i = 0;
	while (C[i] != '\0'){
		
		printf("%c", C[i]);
		i++;
		
	}
	printf("\n");
}

void imprimir2(char* C){
	int i = 0;
	while (*(C+i) != '\0'){
		
		printf("%c", *(C+i));
		i++;
		
	}
	printf("\n");
}

// C++ es lo mismo que escribir C+1 para cada ciclo, entonces *(C+i) es lo que
//implícitamente se está pidiendo a printf
void imprimir3(char* C){
	while (*C != '\0'){
		
		printf("%c\n", *C);
		printf("%p\n", C);
		C++;
		
	}
	printf("\n");
}

	
int main(void) {
	
	char C[4];
	C[0] = 'J';
	C[1] = 'O';
	C[2] = 'H';
	C[3] = 'N';
	printf("%s\n", C);
	//char necesita un caracter nulo,
	//de lo contrario printf imprimirá mal
	char D[5];
	D[0] = 'J';
	D[1] = 'O';
	D[2] = 'H';
	D[3] = 'N';
	D[4] = '\0';
	printf("%s\n", D);
	
	//con estas sintaxis se adiciona un null automáticamente
	
	char E[20] = "John";
	char F[] = "John";
	
	//printf imprime hasta que se encuentra un null 
	//así que no importa si E[20] o E[5] imprime lo mismo
	
	//el tamaño de E es veinte 20 y el de F es 4 + 1
	printf("Size of [E] = %d\n", sizeof(E));
	printf("Length[E] = %d\n", strlen(E));
	printf("Size of [F] = %d\n", sizeof(F));
	printf("Length[F] = %d\n", strlen(F));
	
	//"arrays and pointers are different types that are
	//used in similar manner"
	
	char c1[6] = "Hello";
	char* c2;
	c2 = c1;
	
	//es decir c2 es un pointer to character pero su tratamiento
	//es exactamente igual que un character array y se puede demostrar:
	
	for (int i = 0; i<(6-1); i++){
		//saying c2[i] is the same as *(c2 + i) with pointer to character
		printf("Character of the %d element of c2: %c\n", i, c2[i]);
		printf("Character of the %d element of c2: %c\n", i, *(c2 + i));
	}
	
	char C3[20] = "Hello World";
	
	imprimir1(C3);
	imprimir2(C3);
	imprimir3(C3);
	
	return 0;
}

