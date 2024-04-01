#include <iostream>
#include <cmath>

using namespace std;

//g++ -o run buritica_programming_logic_ch_7_exe.cpp

void endsWithNumber(int);
void haveNDigits(int);
void isNegative();
void twoDigitsSum();
void lessTwentyPrimes();

int main() {
	lessTwentyPrimes();
	//twoDigitsSum();
	//isNegative();
	//haveNDigits(3);
	//endsWithNumber(4);
	return 0;
}

void endsWithNumber(int endsWith) {
	//Read an integer number and determine if it's a number that ends with 4
	int number;
	cout << "Enter an integer: ";
	cin >> number;
	// Get the last digit of the number
	int lastDigit = number % 10;
	// Check if the last digit is 4
	if (lastDigit == endsWith) {
		cout << "The last digit of " << number << " is " << endsWith << endl;
	} else {
		cout << "The last digit of " << number << " is not " << endsWith << endl;
	}
	return;
}

void haveNDigits(int n){
	//Read an integer number and determine if it have 3 digits
	int num;
	int temp;
	int counter = 0;
	cout << "Provide an integer number: ";
	cin >> num;
	num = abs(num);
	temp = abs(num);
	while (num > 0) {
		num = num / 10;
		counter++;
	}
	if (counter == n){
		cout << "The number of digits of " << temp << " is " << n << endl;
	} else {
		cout << "The number of digits of " << temp << " is not " << n << endl;
	}
	return;
}
	
void isNegative(){
	//read a integer number and determine if it's a negative number
	int num;
	cout << "Provide an integer number: ";
	cin >> num;
	if (num > 0){
		cout << "The provided number " << num << " is not a negative number." << endl; 
	} else {
		cout << "The provided number " << num << " is a negative number." << endl; 
	}
	return;
}
	
void twoDigitsSum(){
	//Read an integer number with two digits and determine the sum of its digits.
	int num1;
	int num2;
	int num3;
	cout << "Provide a two digits integer (-100, -10) U (10, 100): ";
	cin >> num1;
	if (abs(num1) < 100 && abs(num1) > 9){
		num2 = num1/10;
		num3 = abs(num1 - num2*10);
		cout << "The digits of " << num1 << " are: " << num2 << " and " << num3 << endl;
		cout << "And its sum is: " << num2 + num3 << endl;
	} else {
		cout << "The provided number must be a two cipher integer" << endl;
		return;
	}
	return;
}
	
void lessTwentyPrimes(){
	int num1;
	cout << "Provide a positive integer between [10, 20): ";
	cin >> num1;
	if (num1 > 9 && num1 < 20){
		// if a number num1 is not a prime, it must have a divisor less than or equal to its square root.
		for (int i = 2; i*i <= num1; i++){
			if (num1 % i == 0){
				cout << "The number " << num1 << " is not a prime number" << endl;
				return;
			}
		}
		cout << "The number " << num1 << " is a prime number" << endl;
		
	} else {
		cout << "The number " << num1 << " is out of range [10, 20)" << endl;
		return;
	}
}
	

