#include <stdio.h>

int main(void) {
	int B[2][3] = {{2,3,6},{4,5,8}};
	int (*p)[3] = B; //pointer to array of tree integers
	//dirección de memoria del primer elemento de B[0]
	printf("%d\n", B);
	printf("%d\n", &B);
	//dirección de memoria del primer elemento de B[0] = B[0][0]
	//porque la llamada al array está incompleta (a B[0] le falta la segunda dimensión para quedar B[0][0] ó B[0][1] etc...)
	//B[0] es para pedir un valor pero como el array es bidimensional devuelve la dirección de memoria del primer elemento
	//del array B[0] osea B[0][0]
	printf("%d\n", B[0]);
	//en este caso B[0] = &B[0] = &B[0][0]
	printf("%d\n", &B[0]);
	printf("%d\n", &B[0][0]);
	//como *B = B[0], *B también devuelve la dirección de B[0][0]
	printf("%d\n", *B);
	//para devolver el valor de B[0][0] se usa la notación completa del array
	printf("%d\n", B[0][0]);
	//recordando que B + i = &B[i], B + i devuelve la dirección de memoria del iésimo elemento
	//B[i] pero como la notación está incompleta devuelve la dirección de memoria del primer elemento
	//del array B[i] es decir B[i][0]
	printf("%d\n", B + 1); // esta dirección de memoria está alejada 12 bytes de la dirección del primer elmento B[0], que 
	//tiene en total 3 elementos de 4 bytes cada uno es decir 12 bytes de longitud: el array multidimensional se 
	//encuentra escrito de forma continua en la memoria de la máquina
	printf("%d\n", B[1]); //como la notación está incompleta devuelve la misma dirección de memoria
	printf("%d\n", *(B+1)); // es de esperar que sea la misma dirección anterior ya que B[i] = *(B+i)
	//si quiero entrar a una dirección de memoria específica necesito la notación para pointers equivalente
	//de &B[i][j]
	printf("%d\n", &B[1][2]);
	//se puede aprovechar sabiendo que otra forma de ciclar en un array es con la notación B[i]+j
	//con B[i] = *(B+i), entonces: B[i] + j = *(B+i) + j
	printf("%d\n", *(B+1)+2);
	printf("%d\n", B[1]+2);
	//finalmente para obtener el valor y no la dirección de memoria se necesita un operador inverso al operador 
	//referencia (&) y eso es lo que precisamente puede hacer un pointer, desreferenciar. Un pointer adelante
	//de algo que sea una variable que guarde una dirección de memoria, la desreferencia, le quita la referencia
	//es decir el operador (&) y devuelve el valor contenido en esa dirección de memoria entonces: *(&X) = valor contenido
	//en la variable X, luego: *(&B[1][2]) = B[1][2]; por extensión: *(*(B+1)+2) = B[1][2];
	printf("%d\n", *(&B[1][2]));
	printf("%d\n", *(*(B+1)+2));

	
	return 0;
}

