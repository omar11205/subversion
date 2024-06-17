#include <iostream>
#include <cmath>
using namespace std;

//cplusplus 201703L
//g++ -o run mclaurin_exponential.cpp

float factorial(int n){
	float fact = 1;
	if (n<0){
		cout << "Error: factorials of negative numbers does not exist.";
	} else {
		for (int i = 1; i <= n; ++i){
			fact *= i; 
		}
		
	}
	return fact;
}
	
float mcex(float x, float n){
	//mcclaurin for e^x
	float term;
	term = pow(x, n)/factorial(n);
	return term;
}

float numericalMethod(float x, float es, long int maxit){
	//x = number to estimate; es = detention criteria; maxit = maximum iterations
	long int iter = 1
	float sol = 1;
}	

int main(int argc, char *argv[]) {
	
	float x = 0.5;
	float n = 2;
	float result = MCex(x, n);
	cout << x << "^" << n << "/" << n << "! = " << result;
	
	return 0;
}

