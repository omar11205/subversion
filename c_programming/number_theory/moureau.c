#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//from: Introduction to number theory with computing (1989)
//proff the Moureau assertion that there are exactly ten integers formed 
//by the sum of two or more different cubes les than 100000. 
//(x^3+y^3 = z^3+t^3 < 100000) 3 posible algorithms are given 

//gcc moureau.c -o moureau

//function agruping the 3 posible solution algoritms
int* moureau(int mode, int solutions) {
	int x, y, z, t, w;
	int u = 0;
	int solCounter = 0;
	int* solArray = (int*)malloc(sizeof(int)*solutions);
	for(int n = 2; n<=74; n++){
		for (x=1; x<=n/2; x++){
			if(mode == 1){
				y = n-x;
			} else if(mode==2 || mode==3){
				y = n-x;
				u = x*x*x + y*y*y;
			} else {
				printf("Invalid mode\n");
				return 0;
			}
			for (z = x+1; z<=y-1; z++){
				if(mode==3){
					w = u - z*z*z;
				}
				for (t=z; t<=y-1; t++){
					if (mode==1 && (x*x*x+y*y*y) == (z*z*z + t*t*t) && (x*x*x+y*y*y)<=100000){
						solArray[solCounter] = (x*x*x+y*y*y);
						//printf("x: %d, y: %d, z: %d, t: %d, x^3+y^3 = %d\n", x, y, z, t, solArray[solCounter]);
						solCounter++;
					} else if (mode==2 && u == (z*z*z + t*t*t) && ((x*x*x+y*y*y))<=100000){
						solArray[solCounter] = (x*x*x+y*y*y);
						//printf("x: %d, y: %d, z: %d, t: %d, x^3+y^3 = %d\n", x, y, z, t, solArray[solCounter]);
						solCounter++;
					} else if (mode==3 && w == t*t*t && ((x*x*x+y*y*y))<=100000){
						solArray[solCounter] = (x*x*x+y*y*y);
						//printf("x: %d, y: %d, z: %d, t: %d, x^3+y^3 = %d\n", x, y, z, t, solArray[solCounter]);
						solCounter++;
					}
					if (solCounter == solutions){
						printf("mode %d required solutions reached: %d\n",mode,solCounter);
						return solArray;
					}
					
				}
			}
		}
	}
	//printf("all posible solutions reached: %d\n", solCounter);
	return solArray;
}

//function for algorithm 1
void algorithm1() {
	int x, y, z, t;
	int c = 0;
	for(int n = 2; n<=74; n++){
		for (x=1; x<=n/2; x++){
			y = n-x;
			for (z = x+1; z<=y-1; z++){
				for (t=z; t<=y-1; t++){
					if ((x*x*x+y*y*y) == (z*z*z + t*t*t) && (x*x*x+y*y*y)<100000){
						//printf("x: %d, y: %d, z: %d, t: %d, x^3+y^3 = %d\n", x, y, z, t, (x*x*x+y*y*y));
						c++;
					} 
					
				}
			}
		}
	}
	printf("algorithm 1 %d solutions reached\n", c);
}

// Function implementing Algorithm 2
void algorithm2() {
	int x, y, z, t;
	int u = 0;
	int c = 0;
	for(int n = 2; n<=74; n++){
		for (x=1; x<=n/2; x++){
			y = n-x;
			u = x*x*x + y*y*y;
			for (z = x+1; z<=y-1; z++){
				for (t = z; t<=y-1; t++){
					if (u == z*z*z + t*t*t && u<100000){
						//printf("n = %d, x = %d, y = %d, z = %d, t = %d, u = %d\n", n, x, y, z, t, u);
						c++;
					} 
					
				}
				
			}
		}
	}
	printf("algorithm 2 %d solutions reached\n", c);
}



// Function implementing Algorithm 3
void algorithm3() {
	int x, y, z, t, w;
	int u = 0;
	int c = 0;
	for(int n = 2; n<=74; n++){
		for (x=1; x<=n/2; x++){
			y = n-x;
			u = x*x*x + y*y*y;
			for (z = x+1; z<=y-1; z++){
				w = u - z*z*z;
				for (t = z; t<=y-1; t++){
					if (w == t*t*t && u<100000){
						//printf("n = %d, x = %d, y = %d, z = %d, t = %d, u = %d\n", n, x, y, z, t, u);
						c++;
					} 
					
				}
				
			}
		}
	}
	printf("algorithm 3 %d solutions reached\n", c);
}


int main(void) {
	clock_t start, end;
	double cpu_time_used;
	
	// Measure execution time for Moureau mode 1
	
	int mode = 1;
	int sols = 10;
	start = clock();
	int* algo1 = moureau(mode, sols);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Moureau function mode 1 took %f seconds to execute.\n", cpu_time_used);
	free(algo1);
	
	// Measure execution time for Moureau mode 2
	
	mode = 2;
	sols = 10;
	start = clock();
	int* algo2 = moureau(mode, sols);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Moureau function mode 2 took %f seconds to execute.\n", cpu_time_used);
	free(algo2);
	
	// Measure execution time for Moureau mode 3
	mode = 3;
	sols = 10;
	start = clock();
	int* algo3 = moureau(mode, sols);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Moureau function mode 3 took %f seconds to execute.\n", cpu_time_used);
	free(algo3);
	
	//Measure execution time for Algorithm 1
	start = clock();
	algorithm1();
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Algorithm 1 took %f seconds to execute.\n", cpu_time_used);
	
	//Measure execution time for Algorithm 2
	start = clock();
	algorithm2();
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Algorithm 2 took %f seconds to execute.\n", cpu_time_used);
	
	
	// Measure execution time for Algorithm 3
	start = clock();
	algorithm3();
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Algorithm 3 took %f seconds to execute.\n", cpu_time_used);
	
	return 0;
}
