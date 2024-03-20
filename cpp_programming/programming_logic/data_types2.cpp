#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	cout << fixed << setprecision(2); //automatically round up the output value with the given presition
	float flotating = 8.9;
	cout << "Flotante: " << flotating << endl;
	
	//double datatype
	double bigfloat = 9.999;
	cout << "Double: " << bigfloat << endl;
	
	//character data type
	char character = 'A';
	char asciiCharacter = 65;
	cout << "Character: " << character << endl;
	cout << "ASCII Character: " << asciiCharacter << endl;

	//there is no need to import <stdbool.h>
	bool bolean = true;
	cout << "Bolean: " << bolean << endl;
	return 0;
}

