#include <iostream>
#include <cmath>

using namespace std;

//g++ -o run buritica_programming_logic_ch_7_exe.cpp

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

int main() {
	//isNegative();
	//haveNDigits(3);
	//endsWithNumber(4);
	return 0;
}

