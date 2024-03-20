//from Programming Logic (Buritica, 2023) 
#include <iostream>
using namespace std;

void example_simple_positive_even() {
	//Build and algorithm that reads a positive integer and determine if is even
	int input;
	cout << "Provide a positive integer: ";
	cin >> input;
	if (input < 0) {
		cout << "The number provided must be a positive integer.";
	} else {
		/* In the division of any integer in C the result must be an integer, so if the result of the operation leads to the use of a flotating data type
		C always floor the answer. So for any odd number (odd_number) in C
		odd_number/2 === floor_rounded_number, therefore, floor_rounded_number*2 will never be equal to odd_number
		in the other hand for any even number (even_number), (even_number/2)*2 === even_number*1 
		*/
		if (input / 2 * 2 == input) { 
			cout << "The provided number is even";
		} else {
			cout << "The provided number is odd";
		}
	}
}

void example_last_digit_comparison() {
	return;
}

int main()
{   
	example_simple_positive_even();
	return 0;
}
