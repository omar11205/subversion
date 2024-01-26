#include <stdio.h>

//from: Introduction to number theory with computing (Allemby et al., 1989)
//prove that 11 is fascinating for the reason that it is the greatest
//integer not expressible as a sum of two (positive) composite integers.
//Note: 1 is not composite.

//gcc eleven_composite.c -o eleven_composite

int isComposite(int n) {
	
	if (n <= 1) {
		return 0; // 0 and 1 are not composite numbers
	}
	
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			return 1; // Number has a factor other than 1 and itself, so it is composite
		}
		
	}
	
	return 0; // Number is not composite
}

void decomposition(int number){
	int toDeco = number;
	//generate all posible combinations for a + b = number
	for (int i = 1;i<number;i++){
		if (toDeco >= 1){
			toDeco--;
		}
		
		//prove if any combination have both composite numbers
		if (isComposite(toDeco) && isComposite(i)){
			printf("The number %d is composed by the composed numbers %d + %d\n", number, i, toDeco);
			return;
		} 
	}
	printf("The number %d is not composed by a pair of composed numbers\n", number);
	return;
}
	
int main(void){
	
	int num;
	int maxAll = 150;
	
	// Input the number from the user
	printf("Enter a maximum of numbers to search (max allowed %d): \n", maxAll);
	scanf("%d", &num);
	if (num <= maxAll){
		for (int i = 1; i<=num; i++){
			decomposition(i);
		}
		
	} else {
		printf("Maximum number out of range (>%d)\n", maxAll);
	}
	
	return 0;
}
