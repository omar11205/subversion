#include <stdio.h>

// Define the ODE function f(x, y)
double f(double x, double y) {
	// Example ODE: dy/dx = x^2 + y^2
	return x*x + y*y;
}

// RK4 method
double rk4(double x0, double y0, double h, double xmax) {
	double k1, k2, k3, k4;
	double x = x0, y = y0;
	
	while (x < xmax) {
		k1 = h * f(x, y);
		k2 = h * f(x + 0.5*h, y + 0.5*k1);
		k3 = h * f(x + 0.5*h, y + 0.5*k2);
		k4 = h * f(x + h, y + k3);
		
		y += (k1 + 2*k2 + 2*k3 + k4) / 6.0;
		x += h;
	}
	
	return y;
}

int main() {
	double x0 = 0.0;    // Initial value of x
	double y0 = 1.0;    // Initial value of y(x0)
	double h = 0.1;     // Step size
	double xmax = 1.0;  // Endpoint
	
	double result = rk4(x0, y0, h, xmax);
	
	printf("Value of y at x = %f: %f\n", xmax, result);
	
	return 0;
}

