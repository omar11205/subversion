/* From Introduction to number theory with computing, Allemby et al. 1989.  
Create an algorithm to proff by bruteforce  the Fermat Last Theorem: 
if n is a positive integer greather than 2, no positive integers X, Y and Z 
satisfy the equation, X^n + Y^n = Z^n */

// for n > 2

//g++ fermat_last_theorem.cpp -o fermat

#include <iostream>
#include <cmath>
using namespace std;

void fermatProff(int limit, int n) {
	
	if (n < 3){
		return;
	}
	
	for (int x=1; x<=limit; x++){
		
		for (int y=x; y<=limit; y++){
			// Check if there exists a triplet
			// such that X^n + Y^n = Z^n
			int pow_sum = pow(x, n) + pow(y, n);
			double z = pow(pow_sum, 1.0/n);
			int z_pow = pow((int)z, n);
			
			if (z_pow == pow_sum){
				cout << "Counter example found";
				return;
			}
		}
	}
	
	cout << "No counter example within given range and data" << endl;
}

// control code
int main(void)
{
	fermatProff(50, 4);
	return 0;
}

