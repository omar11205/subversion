#include <stdio.h>
#include <stdlib.h>

/*generate alleatory whole numbers between 0 to RAND_MAX (32000)*/
/* num = A + rand() % (B - A + 1)*/

int *aleatoryNoSeed(int a, int b, int many){ //a left limit, b right limit
	int i;
	int *res = (int*)malloc(many*sizeof(int)); 
	
	for (i = 0; i<many; i++){
		res[i] =  a + rand()%(b-a+1);
	}
	return res;
	
}

int main(void) {
	int a = 1;
	int b = 6;
	int many = 20;
	int i;
	int *p = aleatoryNoSeed(a,b,many);
	for(i = 0; i<many; i++){
		printf("Aleatory number [%d] = %d\n", i+1, p[i]);
	}
	free(p);
	return 0;
}

