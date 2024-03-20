#include <iostream>
using namespace std;

int main() {
	
	//string is included in the std namespace but char is also valid
	char characterArray[] = "Hello";
	cout << "String 1: " << characterArray << endl;
	
	//string is a class in C++, so it have methods and attributes
	
	string stringC = "Goodbye"; //here we have instanciated a object of class string
	cout << "String 2: " << stringC << endl;
	return 0;
}

