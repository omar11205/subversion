//from Programming Logic (Buritica, 2023) 
#include <iostream>
#include <cmath>
using namespace std;

void example_1_simple_positive_even() {
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

void example_2_last_digit_comparison() {
	//Build and algorithm to read two positive integers and determine if the last digits of the numbers are the same
	int num1;
	int num2;
	cout << "Provide a first positive integer: ";
	cin >> num1;
	cout << "Provide a second positive integer: ";
	cin >> num2;
	if (num1 < 0 || num2 < 0) {
		cout << "You must provide two positive integers";
		return;
	} else {
		int lu1 = num1 - (num1 / 10) * 10;  // if num1 < 10 : num1/10 = 0 therefore, num1 - 0*10 = num1
		int lu2 = num2 - (num2 / 10) * 10;  
		if (lu1 == lu2) {
			cout << "The last digit of number 1: " << lu1 << ", and number 2: " << lu2 << " are the same" << endl;
		} else {
			cout << "The last digit of number 1: " << lu1 << ", and number 2: " << lu2 << " are not the same" << endl;
		}
	}
	return;
	
}

void example_3_number_of_digits() {
	//Read an integer number and determine how many digits it has
	int num;
	int temp;
	int counter = 0;
	cout << "Provide an integer number: ";
	cin >> num;
	num = abs(num);
	temp = num;
	while (num > 0) {
		num = num / 10;
		counter++;
	}
	cout << "The number of digits of " << temp << " is: " << counter << endl;
	return;
}

void example_4_cascade_number_of_digits() {
	//Read an integer number and determine if it has one, two, tree or four digits.
	//Validate if the number is not negative
	int num;
	cout << "Provide an integer number: ";
	cin >> num;
	if (num < 0) {
		num = (-1) * (num);
	} else {
		return; //complete the algorithm
	}
}

int main()
{   
	//example_4_cascade_number_of_digits;
	//example_3_number_of_digits();
	//example_2_simple_positive_even();
	//example_1_last_digit_comparison();
	system("pause>0");
}
