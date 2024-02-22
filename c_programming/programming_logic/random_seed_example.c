/*IMPORTANT! In windows use #include <Windows.h> , in UNIX use #include <unistd.h>*/
/*sleep(2000) = wait 2 seconds in Windows*/
/*sleep(2) = wait 2 seconds in UNIX operating systems*/

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//We want to generate N quadratic equations (ax^2 + bx + c) 
//randomly where each coefficient is an integer within the range [-30, 30].
//Check if the equation has multiple roots, a single root, or no real 
//roots, displaying a message for each case. In the case of real roots existing
//display them.

//discriminant logic: 
//discriminant = b^2 - 4ac 
//if discriminant > 0, the eq has multiple real roots
//if discriminant = 0, the eq has unique root
//if discriminant < 0, the eq has not real roots

int *aleatory(int seed, int min, int max, int many){ //seed = 1 for time seed random generation, a left limit, b right limit,  
	int *res;
	if(max<=min){ //error control
		printf("Interval error: b<=a or b=a \n");
		void *res = malloc(sizeof(int)); //recasting res to a void pointer to return NULL instead 0 
		res = NULL;
		return res;
	} else {
		res = (int*)malloc(many*sizeof(int));
	}
	
	int i;
	
	if(seed == 1){
		printf("Alleatory seed ON\n");
		time_t t;
		srand((unsigned) time(&t));	
	} else {
		printf("Alleatory seed OFF\n");
	}
	
	for (i = 0; i<many; i++){
		res[i] =  min + rand()%(max-min+1);
	}
	return res;
	
}
	
	
int main(void) {
	int n = 10; //number of quadratic equations
	int min = -30;
	int max = 30;
	int many = n;
	int i;
	int *a;
	int *b;
	int *c;
	
	a = aleatory(1, min, max, many);
	Sleep(2000); //if not wait to one or two seconds there is no random time seed and the parameters a,b,c will be equal
	b = aleatory(1, min, max, many);
	Sleep(2000);
	c = aleatory(1, min, max, many); 
	
	if (a != NULL && b != NULL && c != NULL){
		for(i = 0; i<many; i++){
			printf("equation %d = %dx^2 + %dx + %d = 0\n", i+1, a[i], b[i], c[i]);
		}
	} else {
		printf("Alleatory generation failed\n");
	}
	free(a);
	free(b);
	free(c);
	return 0;
}
