#include <stdio.h>
#include <string.h>

/*
The objective is to recreate the same code originally written in python described in:
https://www.freecodecamp.org/learn/scientific-computing-with-python/learn-how-to-work-with-numbers-and-strings-by-implementing-the-luhn-algorithm/ 

The Luhn algorithm is as follows:

From the right to left, double the value of every second digit; if the product is greater than 9, sum the digits of the products.
Take the sum of all the digits.
If the sum of all the digits is a multiple of 10, then the number is valid; else it is not valid.
Assume an example of an account number "7992739871" that will have a check digit added, making it of the form 7992739871x:

Account number      7   9  9  2  7  3  9   8  7  1  x
Double every other  7  18  9  4  7  6  9  16  7  2  x
Sum 2-char digits   7   9  9  4  7  6  9   7  7  2  x 
*/


int main(void) {
	char str[] = "4111-1111-4555-1142";
	printf("%s", str);

	int legth = 10;
	for (int i = 0; i<legth; ++i){
		printf("%d\n", i);
	}
	return 0;
}

