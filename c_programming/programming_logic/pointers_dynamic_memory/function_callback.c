#include <stdio.h>

//Function pointers and callbacks

void A(){
	printf("Hello\n");
}
	
void B(void (*ptr)()){ //function pointer as argument, expecting pointer to function as argument
	ptr(); //call-back function that "ptr" points to
}
	
int main(void){
	//declaring a void function pointer and initializing it passing the adress of A
	void (*p)() = A;
	//calling the function pointer will call-back the void function A
	B(p);
	//it's also valid, because passing the name of a function as argument returns a pointer
	B(A); 
	//when reference to a function (A) is passed to another function (B), then that
	//particular function is called callback function
	return 0;
}

