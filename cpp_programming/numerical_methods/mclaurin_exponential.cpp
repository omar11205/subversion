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

float numericalMethod(float x, float es, int maxit){
	//x = number to estimate; es = detention criteria; maxit = maximum iterations
	int iter = 1; //current iterations
	float sol = 1; //initializing solution for the first term of mclaurin for e^x (1)
	float ea = 0; //initializing absolute error
	float old_sol; //old_solution
	
	do{
		old_sol = sol;
		sol = mcex(x, iter) + sol;
		iter = iter + 1;
		if (sol != 0){
			ea = abs((sol-old_sol)/sol)*100;
		}
	} while(ea>=es || iter>=maxit);
	
	return sol;
}	

int main(int argc, char *argv[]) {
	
	float x = 1;
	float es = 0.1;
	float maxit = 100;
	float result = numericalMethod(x, es, maxit);
	cout << "Result for error of 0.1%: " << result; 
	
	return 0;
}

