/*IMPORTANT! In windows use #include <Windows.h> , in UNIX use #include <unistd.h>*/
/*sleep(2000) = wait 2 seconds in Windows*/
/*sleep(2) = wait 2 seconds in UNIX operating systems*/

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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
		void *res = malloc(sizeof(int)); //casting res to a void pointer to return NULL instead 0 
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

//0 for multiple real roots, 1 for unique root, 2 for non real roots
int* discriminant(int *a, int *b, int *c, int n){
	int *discArr = (int*)malloc(n*sizeof(int));
	int disc;
	int i;
	for(i = 0; i<n; i++){
		disc = (b[i]*b[i]) - 4*a[i]*c[i];
		if (disc > 0){
			discArr[i] = 0;
		} else if (disc == 0){
			discArr[i] = 1;
		} else {
			discArr[i] = 2;
		}
	}
	return discArr;
}	

float *quadraticSolutions(int *a, int *b, int *c, int *d, int n){
	/*float *sol = (float*)malloc(n*sizeof(float));
	for(){
		switch (d){
			case 0:
				
			
		}
	}	 
	return sol;*/
}
	
int main(void) {
	int n = 15; //number of quadratic equations
	int min = -30;
	int max = 30;
	int many = n;
	int i;
	int *a;
	int *b;
	int *c;
	int *d;
	
	a = aleatory(1, min, max, many);
	Sleep(2000); //if not wait to one or two seconds there is no random time seed and the parameters a,b,c will be equal
	b = aleatory(1, min, max, many);
	Sleep(2000);
	c = aleatory(1, min, max, many);
	
	d = discriminant(a, b, c, n);
	
	
	if(a != NULL && b != NULL && c != NULL){
		printf("discriminant: 0 for multiple real roots, 1 for unique root, 2 for no real roots\n"); 
		for(i = 0; i<many; i++){
			printf("equation %d = %dx^2 + %dx + %d = 0, discriminant = %d\n", i+1, a[i], b[i], c[i], d[i]);
		}
	} else {
		printf("Alleatory generation failed\n");
	}
	free(a);
	free(b);
	free(c);
	free(d);
	return 0;
}
