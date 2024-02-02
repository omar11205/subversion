#include <stdio.h>
void PrintHello(char *name){
	printf("Hello %s\n", name);
}

int Add(int a, int b){
	return a+b;
}
	
int main(void) {
	//declaring a pointer to function like Add
	int (*p)(int,int);
	//initializing pointer to function Add means that
	//p points to the adress of the function Add
	//&Add
	p = &Add;
	int c;
	//to execute the function from a pointer
	//dereference with (*) p
	c = (*p)(2,4);
	printf("Result c: %d\n", c);
	//equivalent syntax 
	int (*x)(int, int);
	x = Add;
	int d;
	d = x(3, 4);
	printf("Result d: %d\n", d);
	//with character arrays
	void (*ptr)(char*);
	ptr = PrintHello;
	ptr("Tom");
	return 0;
}

