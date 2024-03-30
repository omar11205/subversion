#include <iostream>


void gauss(int n) {
	int sum = (n * (n + 1)) / 2; 
	// Gauss formula for sum of first n natural numbers	
	std::cout << "The sum of the first " << n << " whole numbers is: " << sum << std::endl;	
	return;
}

void gauss_arithmetic(int a, int d, int n){
	int sum = n / 2 * (2 * a + (n - 1) * d);
	// Gauss formula for the sum of an arithmetic series: sum = n/2 * (2a + (n-1)*d)
	std::cout << "The sum of the arithmetic series is: " << sum << std::endl;
	return;
}

int main() {
	int a = 5; // first term of the arithmetic series
	int d = 3; // common difference
	int n = 10; // number of terms
	gauss_arithmetic(a, d, n);
	return 0;
}

