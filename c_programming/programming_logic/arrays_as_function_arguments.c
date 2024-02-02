#include <stdio.h>
/*
	create a function to sum all the elements of an array
*/
int sumAll(int a[]){
	//an array as a function argument does not copy the array (all the array elements)
	//inside the function
	//instead of that, the compiler create an int* a pointer automatically
	//so the size of an pointer (int* a) is always the size of the type (int), so "sizeof(a) = 4"
	//"sizeof(a[0]) = 4", 4/4 = 1, therefore, sizeof is not longer suitable to get
	//the number of elements of an array inside a function. It is needed to bring the size 
	//from main or whatever the array was declared/created
	int i, sum = 0;
	int size = sizeof(a)/sizeof(a[0]); // = 4/4 = 1
	printf("size of the array inside sumAll: %d\n", size);	
	for (i = 0; i<size; i++){
		sum = sum + a[i];
	}
	return sum;
}
	
int correctedSumAll(int* a, int size){
	int i, sum = 0;
	printf("size of the array inside sumAll: %d\n", size);	
	for (i = 0; i<size; i++){
		sum += a[i];
	}
	return sum;
}

int main(void) {
	int a[] = {1, 2, 3, 4, 5};
	int size = sizeof(a)/sizeof(a[0]);
	printf("size of the array inside main: %d\n", size);
	//int result = sumAll(a);
	int result = correctedSumAll(a, size);
	printf("The sum of all elements of array A is: %d\n", result);
	return 0;
}

