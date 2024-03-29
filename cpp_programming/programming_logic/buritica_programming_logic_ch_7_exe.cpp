#include <iostream>

using namespace std;

bool endsWithFour(int number) {
	// Get the last digit of the number
	int lastDigit = number % 10;
	// Check if the last digit is 4
	return (lastDigit == 4);
}

int main() {
	int number;
	cout << "Enter an integer: ";
	cin >> number;
	
	if (endsWithFour(number)) {
		cout << "The last digit of " << number << " is 4." << endl;
	} else {
		cout << "The last digit of " << number << " is not 4." << endl;
	}
	
	return 0;
}

