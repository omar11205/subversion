#include <stdio.h>
//multidimensional array as function arguments
void manipulate(int (*A)[2][2]){ //Argument: pointer to two dimensional array of two integers (elements)
	printf("%d\n", *(*(*(A+0)+0)+1));
}
	
void manipulate2(int A[][2][2]){ //Argument: Array of unknown i dimensions, j = 2 dimensions, k = 2 elements
	printf("%d\n", *(*(*(A+0)+0)+1));
}
	
int main(void) {
	int B[2][3] = {{2,3,6},{4,5,8}};
	int C[3][2][2] = {{{2,5},{7.9}},{{3,4},{6,1}},{{0,8},{11,13}}};
	int (*p)[2][2] = C; //pointer to two dimensional array of two integers (elements)
	int (*r)[3] = B; //pointer to one dimensional array of two integers (elements)
	//finalmente para obtener el valor y no la dirección de memoria se necesita un operador inverso al operador 
	//referencia (&) y eso es lo que precisamente puede hacer un pointer, desreferenciar. Un pointer adelante
	//de algo que sea una variable que guarde una dirección de memoria, la desreferencia, le quita la referencia
	//es decir el operador (&) y devuelve el valor contenido en esa dirección de memoria entonces: *(&X) = valor contenido
	//en la variable X, luego: *(&B[1][2]) = B[1][2]; por extensión: *(*(B+1)+2) = B[1][2];
	printf("%d\n", *(&B[1][2]));
	printf("%d\n", *(*(B+1)+2));
	
	//para array multidimensionales se extiende la lógica: C[i][j][k] = *(C[i][j]+k) = *(*(C[i]+j)+k) = *(*(*(C+i)+j)+k)
	printf("%d\n", C[0][0][1]);
	printf("%d\n", *(C[0][0]+1));
	printf("%d\n", *(*(C[0]+0)+1));
	printf("%d\n", *(*(*(C+0)+0)+1));
	manipulate(C);
	manipulate2(C);
	
	return 0;
}

