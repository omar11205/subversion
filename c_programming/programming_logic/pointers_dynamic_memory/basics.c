#include <stdio.h>

int main(void) {
	int a;
	//a pointer is a variable, that points another variable.
	//The meaning of "points another variable" is that a pointer stores the address value of
	//another variable in this case int a
	int *p;
	//initializing a
	a = 10;
	p = &a; //assinging the adress of a (&a) as the content of pointer variable p
	printf("Adress of P is in hexadecimal %p \n", p);
	printf("Adress of P is in decimal %d \n", p);
	//*p means "The content of the memory adress stored in p"
	//so here "*p" is the same than "a"
	printf("Value at p is %d\n", *p);
	//the pointer not only stores an adress of another variable, a pointer can
	//modify the value stored in such memory adress with "*p ="
	int b;
	b = 20;
	*p = b; //the value stored in the memory adress of "a" now will change
	printf("NEW Value at p is %d\n", *p);
	
	//pointer arithmetic
	
	printf("%d\n", p);
	printf("%d\n", p+1); //the adress will be incremeted by 4 bytes
	//because if p is an integer pointer and the size of one
	//integer is 4 for most of default c compilers
	printf("size of an integer in my compiler in bytes \n = %d", sizeof(int));
	return 0;
}

