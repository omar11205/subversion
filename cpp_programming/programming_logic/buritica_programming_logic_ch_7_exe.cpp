#include <iostream>
#include <cmath>

//cplusplus 201703L
//g++ -o run buritica_programming_logic_ch_7_exe.cpp

using namespace std;

void endsWithNumber(int);
void haveNDigits(int);
void isNegative();
void twoDigitsSum();
void nDigitsSum(int);
void twoDigitsEven();
void lessTwentyPrimes();
void twoDigitsPrimes();
void twoBothDigitsPrimes();
void twoDigitsMultiple();
void twoDigitsEqual();
void greatherInteger();

int main() {
	greatherInteger();			//11. Read two integers and determine the greater
	//twoDigitsEqual();			//10. Read an integer number of two digits and determine if both digits are equal.
	//twoDigitsMultiple();		//9. Read an integer number of two digits and determine if one digit is a multiple of the other.		
	//twoBothDigitsPrimes();	//8. Read an integer number of two digits and determine if its two digits are prime
	//twoDigitsPrimes();		//7. Read an integer number of two digits and determine if it is prime and also if it is negative.
	//lessTwentyPrimes();		//6. Read an integer number of two digits less than 20 and determine if it is prime.
	//twoDigitsEven();			//5. Read an integer number of two digits and determine if both digits are even.
	//nDigitsSum(3);			//4.1 Read a positive integer number with n digits and determine the sum of its digits.
	//twoDigitsSum();			//4. Read an integer number with two digits and determine the sum of its digits.
	//isNegative();				//3. Read a integer number and determine if it's a negative number.
	//haveNDigits(3);			//2. Read an integer number and determine if it have 3 digits.
	//endsWithNumber(4);		//1. Read an integer number and determine if it's a number that ends with 4.
	return 0;
}

void endsWithNumber(int endsWith) {
	//1. Read an integer number and determine if it's a number that ends with 4.
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
}

void haveNDigits(int n){
	//2. Read an integer number and determine if it have 3 digits.
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
}
	
void isNegative(){
	//3. Read a integer number and determine if it's a negative number.
	int num;
	cout << "Provide an integer number: ";
	cin >> num;
	if (num > 0){
		cout << "The provided number " << num << " is not a negative number." << endl; 
	} else {
		cout << "The provided number " << num << " is a negative number." << endl; 
	}
}
	
void twoDigitsSum(){
	//4. Read an integer number with two digits and determine the sum of its digits.
	int num;
	int firstD;
	int secondD;
	cout << "Provide a two digits integer (-100, -10] U [10, 100): ";
	cin >> num;
	if (abs(num) >= 100 || abs(num) < 10){
		cout << "The provided number must be a two digits integer" << endl;
		return;
	} else {
		firstD = num/10;
		secondD = abs(num - firstD*10);
		cout << "The digits of " << num << " are: " << firstD << " and " << secondD << endl;
		cout << "And its sum is: " << firstD + secondD << endl;
	}
}

void nDigitsSum(int n){
	//4.1 Read a positive integer number with n digits and determine the sum of its digits.
	int num;
	int sum = 0;
	int counter = 0;
	int temp;
	int wtemp;
	
	cout << "Enter a " <<n<<"-digit positive integer: ";
	cin >> num;
	
	//count the digits of the provided number
	if (num < 0){
		cout << "You must provide a positive integer"<< endl;
		return;
	} else {
		wtemp = num; 
		while (wtemp > 0) {
			wtemp = wtemp / 10;
			counter++;
		}
	}

	if (counter != n){
		cout << "You must provide an " <<n<<"-digit positive integer"<< endl;
		return;
	} else {
		temp = num;
		
		for (int i = 0; i<n; i++){
			sum += temp % 10; //Extract the last digit and add it to the sum
			temp /= 10; //removing the last digit
		}
		
		//Display the result 
		cout << "The sum of the digits is: " << sum << endl;
	}
	
}

void twoDigitsEven(){
	//5. Read an integer number of two digits and determine if both digits are even.
	int num;
	int firstD;
	int secondD;
	cout << "Provide a two digits integer (-100, -10] U [10, 100): ";
	cin >> num;
	if (abs(num) >= 100 || abs(num) < 10){
		cout << "The provided number must be a two digits integer" << endl;
		return;
	} else {
		firstD = num/10;
		secondD = abs(num - firstD*10);
		if (firstD / 2 * 2 != firstD || secondD / 2 * 2 != secondD){
			cout << "The digits of " << num << ": " << firstD << " and " << secondD << " aren't even." << endl;
		} else {
			cout << "The digits of " << num << ": " << firstD << " and " << secondD << " are even." << endl;
		}
	}
}	

	
void lessTwentyPrimes(){
	//6.Read an integer number of two digits less than 20 and determine if it is prime.
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

void twoDigitsPrimes(){
	// 7. Read an integer number of two digits and determine if it is prime and also if it is negative.
	int num;
	cout << "Provide a positive integer between [10, 100): ";
	cin >> num;
	if (num <= 1){
		cout << "There are no primes less than or equal to 1" << endl;
		return;
	} else if (num < 10 || num >= 100){
		cout << "The number must be in the range [10, 100)." << endl;
		return;
	} else {
		for (int i = 2; i*i <= num; i++){
			if (num % i == 0){
				cout << "The number " << num << " is not a prime number" << endl;
				return;
			}
		}
		cout << "The number " << num << " is a prime number" << endl;
	}
}
	
void twoBothDigitsPrimes(){
	//8. Read an integer number of two digits and determine if its two digits are prime
	int num;
	int temp;
	int arr[2] = {};
	cout << "Provide a positive integer between [10, 100): ";
	cin >> num;
	if (num <= 1){
		cout << "There are no primes less than or equal to 1" << endl;
		return;
	} else if (num <= 10 || num > 100){
		cout << "The number must be in the range [10, 100)." << endl;
		return;
	} else {
		temp = num;
		for (int i = 0; i<2; i++){
			arr[i] = temp % 10; //Extract the last digit and add it to the array
			temp /= 10; //removing the last digit
		}
		
		for (int j = 0; j<2; j++){ 
			for (int i = 2; i*i <= arr[j]; i++){
				if (arr[j] % i == 0){
					cout << "The digit: " << arr[j] << " from " << num << " is not a prime number" << endl;
					return;
				}
			}
		}
		cout << "The digits " << arr[1] << " and " << arr[0] << " from " << num << " are prime numbers." << endl;
	}
}
	
void twoDigitsMultiple(){
	//9. Read an integer number of two digits and determine if one digit is a multiple of the other.
	// An integer a it's mutiple of another integer b if the residual of a/b its equal to cero
	int num;
	int temp;
	int arr[2] = {};
	cout << "Provide a positive integer between [10, 100): ";
	cin >> num;
	
	if (num < 10 || num > 100){
		
		cout << "The number: " << num << " must be in the range [10, 100)." << endl;
		return;
		
	} else {
		
		temp = num;
		for (int i = 0; i<2; i++){
			arr[i] = temp % 10; //Extract the last digit and add it to the array
			temp /= 10; //removing the last digit
		}
		
		if (arr[0] % arr[1] == 0){
			cout << "The number " << arr[0] << " is multiple of " << arr[1] << endl;
		} else if (arr[1] % arr[0] == 0) {
			cout << "The number " << arr[1] << " is multiple of " << arr[0] << endl;
		} else {
			cout << "Neither digit of " << num << " is a multiple of the other." << endl;
		}
	}
}
	
void twoDigitsEqual(){
	//10. Read an integer number of two digits and determine if both digits are equal.
	int num;
	int arr[2] = {};
	cout << "Provide a positive integer between [10, 100): ";
	cin >> num;
	
	if (num < 10 || num > 100){
		
		cout << "The number: " << num << " must be in the range [10, 100)." << endl;
		return;
		
	} else {
		
		for (int i = 0; i<2; i++){
			arr[i] = num % 10; //Extract the last digit and add it to the array
			num /= 10; //removing the last digit
		}
		
		if (arr[0] == arr[1]){
			cout << "The number " << arr[0] << " is equal to " << arr[1] << endl;
		} else {
			cout << "The number " << arr[0] << " is not equal to " << arr[1] << endl;
		}
	}
}
	
void greatherInteger(){
	//11. Read two integers and determine the greater
	int a;
	int b;
	cout << "Provide an integer number: ";
	cin >> a;
	cout << "Provide another integer number: ";
	cin >> b;
	
	if (a>b){
		cout << "The integer " << a << " is greather than the integer " << b << endl;
	} else if (a<b) {
		cout << "The integer " << b << " is greather than the integer " << a << endl;
	} else {
		cout << "Neither integer is greather than the other (=)" << endl;
	}
}
