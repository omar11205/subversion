#include <stdio.h>

/*
	strong typed pointer variables, void pointers, doble ** and triple *** pointers
*/

int main(void) {
	// if integers have 4 bytes that means 
	// that the integer will be stored in binary like this
	//(last cero) is the sign of the integer. In this case is positive integer -->(0)0000000 00000000 00000100 00000001
	// in denary the number is 1025 [(2^10) = 1024; (2^0) = 1; 2024 + 1 = 1025]
	int a = 1025;
	int *p;
	p = &a;
	printf("Size of integer is %d\n", sizeof(int));
	printf("Adress of p: %p\n", p);
	printf("Value of p: %d\n", *p);
	printf("Adress of p+1: %p\n", p+1);
	printf("Value of p+1: %d\n", *(p+1));
	

	char *p0;
	p0 = (char*)p; //typecasting means triky casting; since p0 is "char*" cannot
	//be equal to p that is "int*" (int p != char p0) so before the "=" assigment operator
	//convert int *p to (char*)p that is semantically legal in C
	printf("Size of character is %d\n", sizeof(char));
	printf("Adress of p0: %p\n", p0);
	printf("Value of p0: %d\n", *p0);
	printf("Adress of p0+1: %d\n", p0+1);
	printf("Value of p0+1: %d\n", *(p0+1));
	
	//void pointer
	
	void *p1;
	p1 = p; //no needing for typecasting, but void pointer will show only the
	//adress of the variable not the content *p1 will get a compilation error
	printf("Adress of void pointer = %p\n", p1);
	
	
	//double pointer, pointer to pointer
	
	int x = 5;
	int *q = &x;
	*q = 6;
	int **r = &q;
	int ***s = &r;
	//call the previous (deleting an asterix) is calling the adress
	printf("%d\n", q);
	printf("%d\n", *r);
	printf("%d\n", **s);
	//calling the whole pointer gives the value stored in that adress
	printf("%d\n", *q);
	printf("%d\n", **r);
	printf("%d\n", ***s);
	
	//aritmetic with pointers
	
	**r = *q + 10;
	printf("The result of *q + 10 is: %d\n", **r);
	
	return 0;
}

