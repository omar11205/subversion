#include <stdio.h>
/*
	ctrl + r, reemplazar todo
*/
//los arreglos de caracteres se manejan en la memoria himp y no en el stack 
//por lo que aunque se cambie por referencia el valor de un array char este cambio
//no se va a ver reflejado en la variable original, fuera de la funci�n, a menos que se retorne
//el cambio y se modifique por la fuerza la variable original.
//void no puede retornar, por tanto se debe usar una funci�n. Ademas el retorno debe ser del mismo tipo que la variable
//que va a recibir el retorno, como char *arg es de tipo apuntador a un arreglo de caracteres
//el tipo de dato de la funci�n tiene que ser de tipo apuntador a un arreglo de 
//caracteres, es decir: char*.
 
char* changeValue(char *parameter){
	//puedo escribir (int *parameter) � (int parameter[]) indistintamente
	parameter = "Adi�s";
	//no hay necesidad de escribir *parametro = "Adi�s" para arreglos
	return parameter;
}


int main(void) {
	//sintaxis v�lida para arrays de caracteres
	//tambi�n es v�lido char* arg = "Hola"
	//tambi�n es usual usar char arg[] = "Hola", pero en este caso no se puede
	//usar porque el tipo de dato del retorno de la funci�n y el tipo de la variable 
	//deben coincidir por lo que ahora no se puede usar esta sintaxis
	char *arg = "Hola";

	printf("Valor string antes: %s\n", arg);
	
	//apuntador = apuntador
	arg = changeValue(arg);

	printf("Valor string despu�s: %s\n", arg);
	
	return 0;
}

