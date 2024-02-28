#include <stdio.h>
#define MAX 40

//typedef defines custom types of variables

typedef struct{
	float x;
	float y;
} tPoint;	//t stands for "custom type", for differenciating with the default datatypes in C

// with this int x; === tInteger x;
typedef int tInteger; 

int main(int argc, char *argv[]) {
	tInteger a = 5;
	tInteger b = -20;
	printf("%d, %d\n", a, b);
	return 0;
}

