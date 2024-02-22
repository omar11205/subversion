#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*generate alleatory whole numbers between 0 to RAND_MAX (32000)*/
/* num = A + rand() % (B - A + 1)*/
/* the function aleatory will return a pointer to an array of randomly generated numbers or NULL is there any problem with the parameters in the calling */
int *aleatory(int seed, int a, int b, int many){ //a left limit, b right limit,  
	int *res;
	if(b<a || b == a){ //control for the 
		printf("Interval error: b<a or b=a \n");
		void *res = malloc(sizeof(int)); //recasting res to a void pointer to return NULL instead 0 
		res = NULL;
		return res;
	} else {
		res = (int*)malloc(many*sizeof(int));
	}
	
	int i;
	
	if(seed == 1){
		printf("Alleatory seed ON\n");
		srand(time(NULL));	
	} else {
		printf("Alleatory seed OFF\n");
	}
	
	for (i = 0; i<many; i++){
		res[i] =  a + rand()%(b-a+1);
	}
	return res;
	
}
	
int main(void) {
	int a = 20;
	int b = 10;
	int many = 20;
	int i;
	int *p;
	
	p = aleatory(1, a, b, many);
	if (p != NULL){
		for(i = 0; i<many; i++){
			printf("Aleatory number seed [%d] = %d\n", i+1, p[i]);
		}
	} else {
		printf("Alleatory generation failed\n");
	}
	free(p);
	return 0;
}
