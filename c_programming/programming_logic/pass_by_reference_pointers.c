#include <stdio.h>

int Increment(int a){
	a = a+1;
	return a;
}
	
void IncrementVoid(int *p){
	*p = *p + 1;
}


int main(void) {
	int a = 10;
	int c;
	int b = Increment(a);
	IncrementVoid(&a);
	printf("Increment of a by return: %d\n", b);
	printf("Increment of a by reference: %d\n", a);
	return 0;
}

