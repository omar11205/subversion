#include<stdio.h>

/* from Programming Logic: (Trejos, 2023) exercises 3.3*/

void one(){
	int a, b, c;
	a = 10;
	b = 20;
	c = 5;
	a = a + 3;
	b = b + 4 - a;
	c = a + b + c;
	a = a + c;
	b = 4;
	c = c + 3 + b + 2;
	printf("a = %d, b = %d, c = %d\n", a, b, c);
}
	
void two(){
	int a, b, c, d;
	a = 5;
	b = 18;
	c = 15;
	d = 25;
	a = a + 10;
	b = b + 5 - c;
	c = c + 4 + b;
	d = d + b + a;
	a = a + 1;
	b = b + c;
	c = b + c;
	d = b + b;
	printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
}

void tree(){
	int a, b;
	a = 9;
	b = 6;
	a = a + 4;
	b = b + 2;
	a = a + 10;
	b = b - 25;
	a = a - 20;
	b = b + 5;
	a = a + 4;
	b = b + 2;
	a = a + 10;
	b = b - 10;    
	printf("a = %d, b = %d\n", a, b);
}

void four(){
	int a, b, c, d;
	a = 18;
	b = 18;
	c = 18;
	d = 18;
	a = a + b;
	b = a - b;
	c = a + b;
	d = a - b;
	a = a - b;
	b = a + b;
	c = a - b;
	d = a + b;    
	printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
}

void fifth(){
	int a, b;
	a = 10;
	b = 5;
	a = a - 5;
	b = b + 6;
	a = a + 18;
	b = b - 23;
	a = a - 21;
	b = b - 5;
	a = a - 4;
	b = b - 2;
	a = a + 10;
	b = b + 10;    
	printf("a = %d, b = %d\n", a, b);
}

void six(){
	int a, b, c, d;
	a = 8;
	b = 7;
	c = 5;
	d = 8;
	a = a + b - c + d;
	b = a + b - c + d;
	c = a + b - c + d;
	d = a + b - c + d;
	a = a + b - c + d;
	b = a + b - c + d;
	c = a + b - c + d;
	d = a + b - c + d;   
	printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
}

int main (void){
	one();
	two();
	tree();
	four();
	fifth();
	six();
	return 0;
}
