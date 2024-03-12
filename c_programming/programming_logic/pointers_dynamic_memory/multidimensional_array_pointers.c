#include <stdio.h>

int main(void) {
	int B[2][3] = {{2,3,6},{4,5,8}};
	int (*p)[3] = B; //pointer to array of tree integers
	//direcci�n de memoria del primer elemento de B[0]
	printf("%d\n", B);
	printf("%d\n", &B);
	//direcci�n de memoria del primer elemento de B[0] = B[0][0]
	//porque la llamada al array est� incompleta (a B[0] le falta la segunda dimensi�n para quedar B[0][0] � B[0][1] etc...)
	//B[0] es para pedir un valor pero como el array es bidimensional devuelve la direcci�n de memoria del primer elemento
	//del array B[0] osea B[0][0]
	printf("%d\n", B[0]);
	//en este caso B[0] = &B[0] = &B[0][0]
	printf("%d\n", &B[0]);
	printf("%d\n", &B[0][0]);
	//como *B = B[0], *B tambi�n devuelve la direcci�n de B[0][0]
	printf("%d\n", *B);
	//para devolver el valor de B[0][0] se usa la notaci�n completa del array
	printf("%d\n", B[0][0]);
	//recordando que B + i = &B[i], B + i devuelve la direcci�n de memoria del i�simo elemento
	//B[i] pero como la notaci�n est� incompleta devuelve la direcci�n de memoria del primer elemento
	//del array B[i] es decir B[i][0]
	printf("%d\n", B + 1); // esta direcci�n de memoria est� alejada 12 bytes de la direcci�n del primer elmento B[0], que 
	//tiene en total 3 elementos de 4 bytes cada uno es decir 12 bytes de longitud: el array multidimensional se 
	//encuentra escrito de forma continua en la memoria de la m�quina
	printf("%d\n", B[1]); //como la notaci�n est� incompleta devuelve la misma direcci�n de memoria
	printf("%d\n", *(B+1)); // es de esperar que sea la misma direcci�n anterior ya que B[i] = *(B+i)
	//si quiero entrar a una direcci�n de memoria espec�fica necesito la notaci�n para pointers equivalente
	//de &B[i][j]
	printf("%d\n", &B[1][2]);
	//se puede aprovechar sabiendo que otra forma de ciclar en un array es con la notaci�n B[i]+j
	//con B[i] = *(B+i), entonces: B[i] + j = *(B+i) + j
	printf("%d\n", *(B+1)+2);
	printf("%d\n", B[1]+2);
	//finalmente para obtener el valor y no la direcci�n de memoria se necesita un operador inverso al operador 
	//referencia (&) y eso es lo que precisamente puede hacer un pointer, desreferenciar. Un pointer adelante
	//de algo que sea una variable que guarde una direcci�n de memoria, la desreferencia, le quita la referencia
	//es decir el operador (&) y devuelve el valor contenido en esa direcci�n de memoria entonces: *(&X) = valor contenido
	//en la variable X, luego: *(&B[1][2]) = B[1][2]; por extensi�n: *(*(B+1)+2) = B[1][2];
	printf("%d\n", *(&B[1][2]));
	printf("%d\n", *(*(B+1)+2));

	
	return 0;
}

