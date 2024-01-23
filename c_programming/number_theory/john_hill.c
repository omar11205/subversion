#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//gcc john_hill.c -o john_hill -lm

//from: Introduction to number theory with computing, 1989
//"On the other hand conjetures are disproved by finding counterexamples
//and computers can be quite helpfull in this regard. For instance, John Hill
//asserted (1727) that 139854276 (=11826^2) is the only perfect square which
//involves all nine non-zero digits once and once only."

//disproff by bruteforce counterexamples;

int* johnHill(int cicles, int numberDisp){ //Number of cicles, number of disproving numbers
	//int disp[numberDisp];
	int *disp = (int*)malloc(numberDisp*sizeof(int)); //Array to store the counterexamples
	int dispCounter = 0;
	for (int n = 0; n < cicles; n++){
		int number[9] = {1,2,3,4,5,6,7,8,9}; //Default seed
		bool usedDigits[10] = {false}; // Array to track the used digits
		int result = 0;
		float fVar;
		int intVar;
		// Generar los 9 dígitos
		for (int i = 0; i < 9; i++) {
			int digit;
			do {
				digit = rand() % 9+1; // Generate an aleatory digit between 1 and 9 including 1 and 9
			} while (usedDigits[digit]); // Verify if the digit has already been used
			
			number[i] = digit;
			usedDigits[digit] = true; // Mark the dígit as used
		}
		
		//from int array to int 
		for (int i = 0; i < 9; i++) {
			result = result * 10 + number[i];
		}
		
		//find the square root, (double) is typecasting
		fVar=sqrt((double)result);
		
		//intVar stores only the integer part
		intVar = fVar;
		
		if(intVar*intVar == result && dispCounter < numberDisp){
			printf("%d is a perfect square.\n",result);
			printf("total number of cicles: %d \n", n);
			disp[dispCounter] = result;
			for (int i = 0; i<=dispCounter; i++){
				printf("number stored %d = %d\n", i, disp[i]);
			}
			dispCounter++;
			if (dispCounter == numberDisp){
				break;
			}
		}
	}
	
	return disp;
}
	
void printToCSV(int *disproffArray, int num){
	FILE *disproffOutput;
	disproffOutput = fopen("disproffJohnHill.csv", "w");
	fprintf(disproffOutput, "ID, Number\n");
	for (int i = 0; i <= num; i++){
		fprintf(disproffOutput, "%d, %d\n", i, disproffArray[i]);
	}
	fclose(disproffOutput);
	free(disproffArray);
}

int main(void) {
	int num = 10;
	int cicl = 300000;
	int *disproffArray = johnHill(cicl, num);
	//printToCSV(disproffArray, num);
	free(disproffArray);
	return 0;
}
