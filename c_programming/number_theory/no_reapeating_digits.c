/*auth: omar11205*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Generate an aleatory number of 10 digits without repeating them

int main() {
	int number[9] = {1,2,3,4,5,6,7,8,9}; //default seed
	bool usedDigits[10] = {false}; // array to track the used digits
	int result = 0;
	
	for (int i = 0; i < 9; ++i) {
		int digit;
		do {
			digit = rand() % 9+1; // Generate an aleatory digit between 1 and 9 including 1 and 9
		} while (usedDigits[digit]);// Verify if the digit has already been used
		
		number[i] = digit;
		usedDigits[digit] = true; // Mark the dígit as used
		for (int i = 0; i < 9; ++i) {
			printf("%d", number[i]);
		}
		printf("\n");
		for (int i = 0; i<10; i++){
			printf("%d", usedDigits[i]);
		}
		printf("\n");
	}
	
	//from int-array to int 
	for (int i = 0; i < 9; ++i) {
		result = result * 10 + number[i];
	}
	
	printf("Resulting integer: %d\n", result);
	return 0;
}

