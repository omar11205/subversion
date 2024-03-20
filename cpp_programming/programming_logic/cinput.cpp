#include <iostream>
using namespace std;

int main() {
	int integer;
	cout << "Provide an integer: " << endl;
	//cin ask for an input in the console and store it in the desired variable
	cin >> integer;
	cout << "Provided integer: " << integer << endl;
	
	// with cin the spaces can not be recognized and stored in the variable 
	//instead use getline(cin, name) never the less cin.ignore() is needed to 
	//clear the buffer of the previous cin calls
	
	string fullname;
	cout << "Provide your name again: " << endl;
	cin.ignore(); //cin is a method of the class std
	getline(cin, fullname);
	cout << "Provided name: " << fullname << endl;
	
	return 0;
}

