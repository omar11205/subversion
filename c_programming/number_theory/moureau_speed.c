/*auth: Allenby & Redfern, (1989); omar11205*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//from: Introduction to number theory with computing (1989)
//proff the Moureau assertion that there are exactly ten integers formed 
//by the sum of two or more different cubes les than 100000. 
//(x^3+y^3 = z^3+t^3 < 100000)

int* moureau(int mode, int numberSol) {
	int solCounter = 0;
	int u = 0;
	int *solutions = (int*)malloc(numberSol*sizeof(int));
	int x, y, z, t;
	for(int n = 2; n<=74; n++){
		for (x=1; x<=n/2; x++){
			if (mode == 1){
				y = n-x;
				u = x*x*x + y*y*y;
			} else if (mode == 0) {
				y = n-x;
			} else {
				printf("No allowed mode\n");
				return 0;
			}
			for (z = x+1; z<=y-1; z++){
				for (t = z; t<=y-1; t++){
					if (mode == 1 && u == z*z*z + t*t*t && u <= 100000){
						solutions[solCounter] = u;
						solCounter++;
					} else if (mode == 0 && (x*x*x+y*y*y) == (z*z*z + t*t*t) && (x*x*x+y*y*y) <= 100000){
						solutions[solCounter] = x*x*x+y*y*y;
						solCounter++;
					}
					if (solCounter == numberSol){
						return solutions;
					}
				}	
			}
		}
	}
	return solutions;
}

void printSolution(int mode, int numberSol){
	int* moureauM = moureau(mode, numberSol);
	for (int i = 0; i<numberSol; i++){
		printf("number %d - %d\n", i+1, moureauM[i]);
	}
	free(moureauM);
}
	
void printToCSV(int mode, int numberSol){
	int* moureauM = moureau(mode, numberSol);
	FILE *Output;
	Output = fopen("moureauNumbers.csv", "w");
	fprintf(Output, "ID, Number\n");
	for (int i = 0; i < numberSol; i++){
		fprintf(Output, "%d, %d\n", i, moureauM[i]);
	}
	fclose(Output);
	printf("CSV printed\n");
	free(moureauM);
}

void runTime(int mode, int numberSol, int * (*moureauf)(int, int)){
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	int* moureauM = moureauf(mode, numberSol);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Algorithm %d took %f seconds to execute.\n", mode, cpu_time_used);
	free(moureauM);
}

int main(void) {
	clock_t start, end;
	double cpu_time_used;
	int numberSol = 10; //maximum theoretical solutions
	int mode1 = 0;
	int mode2 = 1;
	
	runTime(mode1, numberSol, moureau);
	runTime(mode2, numberSol, moureau);
	printSolution(mode1, numberSol);
	printToCSV(mode1, numberSol);
	
	return 0;
}
